#include "FDSan.h"
#include <tiffio.hxx>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
//<ID> 581
//<Prompt> ["TIFFStreamOpen","TIFFNumberOfDirectories","TIFFSetDirectory","TIFFErrorExtR","TIFFGetSeekProc","TIFFGetField","TIFFSwabLong","_TIFFmalloc","TIFFRasterScanlineSize64","TIFFReadScanline","TIFFUnlinkDirectory","_TIFFfree","TIFFClose"]
/*<Combination>: [TIFF *TIFFStreamOpen(const char * , std::ostream * ),
    tdir_t TIFFNumberOfDirectories(TIFF * ),
    int TIFFSetDirectory(TIFF * , tdir_t ),
    void TIFFErrorExtR(TIFF * , const char * , const char * ),
    TIFFSeekProc TIFFGetSeekProc(TIFF * ),
    int TIFFGetField(TIFF * tif, uint32_t tag),
    void TIFFSwabLong(uint32_t * ),
    void *_TIFFmalloc(tmsize_t s),
    uint64_t TIFFRasterScanlineSize64(TIFF * tif),
    int TIFFReadScanline(TIFF * tif, void * buf, uint32_t row, uint16_t sample),
    int TIFFUnlinkDirectory(TIFF * , tdir_t ),
    void _TIFFfree(void * p),
    void TIFFClose(TIFF * tif)
*/
//<score> 15.333333, nr_unique_branch: 1
//<Quality> {"density":23,"unique_branches":{"_TIFFVGetField":[[1255,9,1255,31,0,0,4,0]]},"library_calls":["TIFFStreamOpen","TIFFNumberOfDirectories","TIFFSetDirectory","TIFFErrorExtR","TIFFFileName","TIFFGetSeekProc","TIFFGetField","TIFFErrorExtR","TIFFFileName","TIFFSwabLong","_TIFFmalloc","TIFFRasterScanlineSize64","TIFFErrorExtR","TIFFFileName","TIFFScanlineSize64","TIFFReadScanline","TIFFErrorExtR","TIFFFileName","_TIFFfree","TIFFUnlinkDirectory","TIFFErrorExtR","TIFFFileName","TIFFClose"],"critical_calls":["TIFFStreamOpen","TIFFNumberOfDirectories","TIFFSetDirectory","TIFFErrorExtR","TIFFFileName","TIFFGetSeekProc","TIFFGetField","TIFFErrorExtR","TIFFFileName","TIFFSwabLong","_TIFFmalloc","TIFFRasterScanlineSize64","TIFFErrorExtR","TIFFFileName","TIFFScanlineSize64","TIFFReadScanline","TIFFErrorExtR","TIFFFileName","_TIFFfree","TIFFUnlinkDirectory","TIFFErrorExtR","TIFFFileName","TIFFClose"],"visited":2}
/**/
extern "C" int LLVMFuzzerTestOneInput_41(const uint8_t* data, size_t size) {
	if(size<0) return 0;

	FILE *input_file_ptr = fopen("input_file", "wb");
	if (input_file_ptr == NULL) {return 0;}
	fwrite(data, sizeof(uint8_t), size, input_file_ptr);
	fclose(input_file_ptr);

    // Write data into input_file.
    FILE* in_file = fopen("input_file", "wb");
    if (in_file == NULL) {
        assert_file_closed(&in_file);
	return 0;
    }
    fwrite(data, sizeof(uint8_t), size, in_file);
    assert_file_closed(&in_file);;

    // Open input tiff in memory
    std::istringstream s(std::string(data, data + size));
    TIFF* in_tif = TIFFStreamOpen("MemTIFF", &s);
    if (!in_tif) {
        assert_file_closed(&in_file);
	return 0;
    }

    // Get the number of directories in the input tiff
    tdir_t num_directories = TIFFNumberOfDirectories(in_tif);

    // Iterate through each directory
    for (tdir_t dir_index = 0; dir_index < num_directories; dir_index++) {
        // Set the current directory
        if (!TIFFSetDirectory(in_tif, dir_index)) {
            TIFFErrorExtR(in_tif, TIFFFileName(in_tif), "Failed to set directory");
            continue;
        }

        // Get the seek proc for the current tiff
        TIFFSeekProc seek_proc = TIFFGetSeekProc(in_tif);

        // Get the value of a specific tag
        uint32_t tag_value;
        if (!TIFFGetField(in_tif, TIFFTAG_FILLORDER, &tag_value)) {
            TIFFErrorExtR(in_tif, TIFFFileName(in_tif), "Failed to get field");
            continue;
        }

        // Swab the value if necessary
        TIFFSwabLong(&tag_value);

        // Allocate memory for a scanline buffer
        void* scanline_buffer = _TIFFmalloc(TIFFRasterScanlineSize64(in_tif));
        if (!scanline_buffer) {
            TIFFErrorExtR(in_tif, TIFFFileName(in_tif), "Failed to allocate memory for scanline buffer");
            continue;
        }

        // Read each scanline in the current directory
        uint32_t image_height = TIFFScanlineSize64(in_tif);
        for (uint32_t row = 0; row < image_height; row++) {
            if (TIFFReadScanline(in_tif, scanline_buffer, row, 0) == -1) {
                TIFFErrorExtR(in_tif, TIFFFileName(in_tif), "Failed to read scanline");
                break;
            }
        }

        // Free the scanline buffer
        _TIFFfree(scanline_buffer);

        // Unlink the current directory
        if (!TIFFUnlinkDirectory(in_tif, dir_index)) {
            TIFFErrorExtR(in_tif, TIFFFileName(in_tif), "Failed to unlink directory");
            continue;
        }
    }

    // Close the input tiff
    TIFFClose(in_tif);

    // Release all allocated resources
    // assert_file_closed(&in_file);;
    // remove("input_file");

    assert_file_closed(&in_file);
	return 0;
}