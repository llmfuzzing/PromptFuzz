#include "FDSan.h"
#include "FuzzedDataProvider.h"
#include <tiffio.hxx>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
//<ID> 1895
//<Prompt> ["TIFFStreamOpen","TIFFRasterScanlineSize","TIFFCurrentTile","TIFFWarningExtR","TIFFLastDirectory","TIFFSetDirectory","TIFFGetField","_TIFFmalloc","TIFFClose"]
/*<Combination>: [TIFF *TIFFStreamOpen(const char * , std::ostream * ),
    tmsize_t TIFFRasterScanlineSize(TIFF * tif),
    uint32_t TIFFCurrentTile(TIFF * tif),
    void TIFFWarningExtR(TIFF * , const char * , const char * ),
    int TIFFLastDirectory(TIFF * ),
    int TIFFSetDirectory(TIFF * , tdir_t ),
    int TIFFGetField(TIFF * tif, uint32_t tag),
    void *_TIFFmalloc(tmsize_t s),
    void TIFFClose(TIFF * tif)
*/
//<score> 10, nr_unique_branch: 1
//<Quality> {"density":10,"unique_branches":{"unixWarningHandler":[[355,9,355,23,0,0,4,1]]},"library_calls":["TIFFStreamOpen","TIFFRasterScanlineSize","TIFFCurrentTile","TIFFWarningExtR","TIFFLastDirectory","TIFFSetDirectory","TIFFGetField","_TIFFmalloc","TIFFClose","_TIFFfree"],"critical_calls":["TIFFStreamOpen","TIFFRasterScanlineSize","TIFFCurrentTile","TIFFWarningExtR","TIFFLastDirectory","TIFFSetDirectory","TIFFGetField","_TIFFmalloc","TIFFClose","_TIFFfree"],"visited":1}
/**/
extern "C" int LLVMFuzzerTestOneInput_68(const uint8_t* f_data, size_t f_size) {
	if(f_size<14) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytes(const uint8_t *, data, size, fdp)
		FDPConsumeRandomLengthString(char, fuzz_str_1, fuzz_str_sz_1, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_2, fdp);
	//fuzzer shim end}




    // write data into input_file.
    FILE* in_file = fopen("input_file", "wb");
    if (in_file == NULL) {
        assert_file_closed(&in_file);
	return 0;
    }
    fwrite(data, sizeof(uint8_t), size, in_file);
    assert_file_closed(&in_file);;

    // open input tiff in memory
    std::istringstream s(std::string(data, data + size));
    TIFF* in_tif = TIFFStreamOpen(fuzz_str_1, &s);
    if (!in_tif) {
        assert_file_closed(&in_file);
	return 0;
    }

    // Get the raster scanline size
    tmsize_t scanline_size = TIFFRasterScanlineSize(in_tif);

    // Get the current tile
    uint32_t current_tile = TIFFCurrentTile(in_tif);

    // Display any warning messages during TIFF operations
    TIFFWarningExtR(in_tif, nullptr, "Warning message");

    // Check if it is the last directory
    int is_last_directory = TIFFLastDirectory(in_tif);

    // Set the directory
    int set_directory_success = TIFFSetDirectory(in_tif, fuzz_uint32_t_2);

    // Get a TIFF field value
    uint32_t field_value;
    int get_field_success = TIFFGetField(in_tif, TIFFTAG_IMAGEWIDTH, &field_value);

    // Allocate memory
    void* memory = _TIFFmalloc(scanline_size);

    // Close the input TIFF file
    TIFFClose(in_tif);

    // Release all allocated resources
    _TIFFfree(memory);

    assert_file_closed(&in_file);
	return 0;
}