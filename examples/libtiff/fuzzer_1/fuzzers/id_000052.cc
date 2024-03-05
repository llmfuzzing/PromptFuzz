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
//<ID> 1007
//<Prompt> ["TIFFStreamOpen","_TIFFmalloc","TIFFWriteScanline","TIFFGetClientInfo","TIFFSetClientdata","TIFFRasterScanlineSize","TIFFSwabLong8","_TIFFcalloc","TIFFScanlineSize64","TIFFFindField","TIFFReadRGBAStrip","TIFFFieldSetGetSize","_TIFFfree","TIFFClose"]
/*<Combination>: [TIFF *TIFFStreamOpen(const char * , std::ostream * ),
    void *_TIFFmalloc(tmsize_t s),
    int TIFFWriteScanline(TIFF * tif, void * buf, uint32_t row, uint16_t sample),
    void *TIFFGetClientInfo(TIFF * , const char * ),
    thandle_t TIFFSetClientdata(TIFF * , thandle_t ),
    tmsize_t TIFFRasterScanlineSize(TIFF * tif),
    void TIFFSwabLong8(uint64_t * ),
    void *_TIFFcalloc(tmsize_t nmemb, tmsize_t siz),
    uint64_t TIFFScanlineSize64(TIFF * tif),
    const TIFFField *TIFFFindField(TIFF * , uint32_t , TIFFDataType ),
    int TIFFReadRGBAStrip(TIFF * , uint32_t , uint32_t * ),
    int TIFFFieldSetGetSize(const TIFFField * ),
    void _TIFFfree(void * p),
    void TIFFClose(TIFF * tif)
*/
//<score> 11, nr_unique_branch: 0
//<Quality> {"density":11,"unique_branches":{},"library_calls":["TIFFStreamOpen","TIFFRasterScanlineSize","_TIFFmalloc","TIFFClose","TIFFScanlineSize64","TIFFFieldSetGetSize","TIFFFindField","TIFFReadScanline","TIFFWriteScanline","_TIFFfree","TIFFClose"],"critical_calls":["TIFFStreamOpen","TIFFRasterScanlineSize","_TIFFmalloc","TIFFScanlineSize64","TIFFFieldSetGetSize","TIFFFindField","TIFFReadScanline","TIFFWriteScanline","_TIFFfree","TIFFClose"],"visited":0}
/*Here is the complete implementation of the `LLVMFuzzerTestOneInput_52` function using the provided libtiff APIs:

*/


extern "C" int LLVMFuzzerTestOneInput_52(const uint8_t* f_data, size_t f_size) {
	if(f_size<22) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytes(const uint8_t *, data, size, fdp)
		FDPConsumeRandomLengthString(char, fuzz_str_1, fuzz_str_sz_1, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_2, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_3, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_4, fdp);
	//fuzzer shim end}




  // Write data into input_file
  FILE *in_file = fopen("input_file", "wb");
  if (in_file == NULL) {
    assert_file_closed(&in_file);
	return 0;
  }
  fwrite(data, sizeof(uint8_t), size, in_file);
  assert_file_closed(&in_file);;

  // Open input TIFF in memory
  std::istringstream s(std::string(data, data + size));
  TIFF *in_tif = TIFFStreamOpen(fuzz_str_1, &s);
  if (!in_tif) {
    assert_file_closed(&in_file);
	return 0;
  }

  // Allocate memory for scanline buffer
  tmsize_t scanline_size = TIFFRasterScanlineSize(in_tif);
  void* scanline_buf = _TIFFmalloc(scanline_size);
  if (!scanline_buf) {
    TIFFClose(in_tif);
    assert_file_closed(&in_file);
	return 0;
  }

  // Read and process each scanline
  uint32_t height = TIFFScanlineSize64(in_tif);
  uint16_t samples_per_pixel = TIFFFieldSetGetSize(TIFFFindField(in_tif, fuzz_uint32_t_2, TIFF_NOTYPE));
  for (uint32_t row = 0; row < height; row++) {
    if (TIFFReadScanline(in_tif, scanline_buf, fuzz_uint32_t_3, samples_per_pixel) < 0) {
      break;
    }
    // Process the scanline data here
    // ...

    // Write the processed scanline to the output TIFF
    TIFFWriteScanline(in_tif, scanline_buf, fuzz_uint32_t_4, samples_per_pixel);
  }

  // Clean up resources
  _TIFFfree(scanline_buf);
  TIFFClose(in_tif);

  assert_file_closed(&in_file);
	return 0;
}