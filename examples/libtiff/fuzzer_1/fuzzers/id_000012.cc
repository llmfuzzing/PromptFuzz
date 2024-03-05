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
//<ID> 142
//<Prompt> ["TIFFStreamOpen","TIFFOpen","TIFFGetField","_TIFFmalloc","TIFFRasterScanlineSize64","_TIFFmalloc","TIFFReadEncodedTile","TIFFComputeTile","TIFFWriteEncodedTile","_TIFFfree","TIFFClose"]
/*<Combination>: [TIFF *TIFFStreamOpen(const char * , std::ostream * ),
    TIFF *TIFFOpen(const char * filename, const char * mode),
    int TIFFGetField(TIFF * tif, uint32_t tag),
    void *_TIFFmalloc(tmsize_t s),
    uint64_t TIFFRasterScanlineSize64(TIFF * tif),
    void *_TIFFmalloc(tmsize_t s),
    tmsize_t TIFFReadEncodedTile(TIFF * tif, uint32_t tile, void * buf, tmsize_t size),
    uint32_t TIFFComputeTile(TIFF * tif, uint32_t x, uint32_t y, uint32_t z, uint16_t s),
    tmsize_t TIFFWriteEncodedTile(TIFF * tif, uint32_t tile, void * data, tmsize_t cc),
    void _TIFFfree(void * p),
    void TIFFClose(TIFF * tif)
*/
//<score> 26, nr_unique_branch: 9
//<Quality> {"density":13,"unique_branches":{"TIFFRasterScanlineSize64":[[334,9,334,51,0,0,4,0],[334,9,334,51,0,0,4,1],[296,6,296,16,2,0,4,0],[296,6,296,16,2,0,4,1],[296,6,296,16,3,0,4,0],[296,6,296,16,3,0,4,1]],"TIFFWriteEncodedTile":[[38,47,38,79,1,0,4,1]],"TIFFWriteCheck":[[607,9,607,24,0,0,4,0],[610,23,610,28,0,0,4,0]]},"library_calls":["TIFFStreamOpen","TIFFGetField","TIFFGetField","TIFFRasterScanlineSize64","_TIFFmalloc","TIFFClose","TIFFReadEncodedTile","TIFFComputeTile","TIFFOpen","TIFFWriteEncodedTile","TIFFClose","_TIFFfree","TIFFClose"],"critical_calls":["TIFFStreamOpen","TIFFGetField","TIFFGetField","TIFFRasterScanlineSize64","_TIFFmalloc","TIFFReadEncodedTile","TIFFComputeTile","TIFFOpen","TIFFWriteEncodedTile","TIFFClose","_TIFFfree","TIFFClose"],"visited":1}
/*Here is the completed code for the fuzz driver:

*/


extern "C" int LLVMFuzzerTestOneInput_12(const uint8_t* f_data, size_t f_size) {
	if(f_size<36) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytes(const uint8_t *, data, size, fdp)
		FDPConsumeRandomLengthString(char, fuzz_str_1, fuzz_str_sz_1, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_2, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_3, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_4, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_5, fdp);
		FDPConsumeIntegral(uint16_t, fuzz_uint16_t_6, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_7, fuzz_str_sz_7, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_8, fdp);
	//fuzzer shim end}




    // Write data into input_file
    FILE* in_file = fopen("input_file", "wb");
    if (in_file == NULL) {
        assert_file_closed(&in_file);
	return 0;
    }
    fwrite(data, sizeof(uint8_t), size, in_file);
    assert_file_closed(&in_file);;

    // Open input tiff in memory
    std::istringstream s(std::string(data, data + size));
    TIFF* in_tif = TIFFStreamOpen(fuzz_str_1, &s);
    if (!in_tif) {
        assert_file_closed(&in_file);
	return 0;
    }
    
    // Read some fields from the input tiff
    uint32_t width, height;
    if (TIFFGetField(in_tif, TIFFTAG_IMAGEWIDTH, &width) &&
        TIFFGetField(in_tif, TIFFTAG_IMAGELENGTH, &height)) {
        std::cout << "Image size: " << width << "x" << height << std::endl;
    }

    // Allocate memory for a scanline
    tmsize_t scanline_size = TIFFRasterScanlineSize64(in_tif);
    void* scanline_data = _TIFFmalloc(scanline_size);
    if (!scanline_data) {
        TIFFClose(in_tif);
        assert_file_closed(&in_file);
	return 0;
    }

    // Read encoded tile and compute tile coordinates
    uint32_t tile_x = 0, tile_y = 0, tile_z = 0, tile_s = 0;
    TIFFReadEncodedTile(in_tif, fuzz_uint32_t_2, scanline_data, scanline_size);
    TIFFComputeTile(in_tif, fuzz_uint32_t_3, fuzz_uint32_t_4, fuzz_uint32_t_5, fuzz_uint16_t_6);

    // Write encoded tile to output tiff
    TIFF* out_tif = TIFFOpen("output_file", fuzz_str_7);
    if (out_tif) {
        TIFFWriteEncodedTile(out_tif, fuzz_uint32_t_8, scanline_data, scanline_size);
        TIFFClose(out_tif);
    }

    // Free memory and close tiffs
    _TIFFfree(scanline_data);
    TIFFClose(in_tif);

    assert_file_closed(&in_file);
	assert_file_name_closed("output_file");
	return 0;
}