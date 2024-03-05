#include "FDSan.h"
#include "FuzzedDataProvider.h"
#include <zlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
//<ID> 1099
//<Prompt> ["gzopen","gzopen64","gzeof","gzread","gzbuffer","gztell64","inflateSync","gzflush","deflateSetDictionary","deflateTune","inflateGetHeader","gzputc","gzdirect","adler32_combine","gzclose"]
/*<Combination>: [gzFile gzopen(const char * , const char * ),
    gzFile gzopen64(const char * , const char * ),
    int gzeof(gzFile file),
    int gzread(gzFile file, voidp buf, unsigned int len),
    int gzbuffer(gzFile file, unsigned int size),
    off64_t gztell64(gzFile ),
    int inflateSync(z_streamp strm),
    int gzflush(gzFile file, int flush),
    int deflateSetDictionary(z_streamp strm, const Bytef * dictionary, uInt dictLength),
    int deflateTune(z_streamp strm, int good_length, int max_lazy, int nice_length, int max_chain),
    int inflateGetHeader(z_streamp strm, gz_headerp head),
    int gzputc(gzFile file, int c),
    int gzdirect(gzFile file),
    uLong adler32_combine(uLong , uLong , off_t ),
    int gzclose(gzFile file)
*/
//<score> 9, nr_unique_branch: 0
//<Quality> {"density":9,"unique_branches":{},"library_calls":["gzopen","gzeof","gzread","gzbuffer","gztell64","inflateSync","gzflush","deflateSetDictionary","deflateTune","inflateGetHeader","gzputc","gzdirect","adler32_combine","gzclose"],"critical_calls":["gzopen","gzeof","gzread","gzbuffer","gztell64","inflateSync","gzflush","deflateSetDictionary","deflateTune","inflateGetHeader","gzputc","gzdirect","adler32_combine","gzclose"],"visited":0}
/**/


extern "C" int LLVMFuzzerTestOneInput_68(const uint8_t* f_data, size_t f_size) {
	if(f_size<45) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytes(const uint8_t *, data, size, fdp)
		FDPConsumeRandomLengthString(char, fuzz_str_1, fuzz_str_sz_1, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_2, fdp);
		FDPConsumeIntegral(int32_t, fuzz_int32_t_3, fdp);
		FDPConsumeIntegral(int32_t, fuzz_int32_t_4, fdp);
		FDPConsumeIntegral(int32_t, fuzz_int32_t_5, fdp);
		FDPConsumeIntegral(int32_t, fuzz_int32_t_6, fdp);
		FDPConsumeIntegral(int32_t, fuzz_int32_t_7, fdp);
		FDPConsumeIntegral(uint64_t, fuzz_uint64_t_8, fdp);
		FDPConsumeIntegral(uint64_t, fuzz_uint64_t_9, fdp);
	//fuzzer shim end}
	FILE *input_file_ptr = fopen("input_file", "wb");
	if (input_file_ptr == NULL) {return 0;}
	fwrite(data, sizeof(uint8_t), size, input_file_ptr);
	fclose(input_file_ptr);





    // Step 4: Create input and output file pointers
    FILE* in_file = fmemopen((void*)data, size, "rb");
    FILE* out_file = fopen("output_file", "wb");
  
    // Step 5: Get file descriptors
    int in_fd = fuzz_fileno(in_file);
    int out_fd = fuzz_fileno(out_file);
  
    // Step 2: Use zlib APIs to achieve event
    
    // gzopen
    gzFile gz = gzopen("input_file", fuzz_str_1);
  
    // gzeof
    int eof = gzeof(gz);
  
    // gzread
    char buffer[1024];
    int read_result = gzread(gz, buffer, sizeof(buffer));
  
    // gzbuffer
    gzbuffer(gz, fuzz_uint32_t_2);
  
    // gztell64
    off64_t tell64 = gztell64(gz);
  
    // inflateSync
    z_stream strm;
    inflateSync(&strm);
  
    // gzflush
    gzflush(gz, fuzz_int32_t_3);
  
    // deflateSetDictionary
    Bytef dictionary[1024];
    int dictLength = sizeof(dictionary);
    deflateSetDictionary(&strm, dictionary, dictLength);
  
    // deflateTune
    int good_length = 256;
    int max_lazy = 8;
    int nice_length = 32;
    int max_chain = 16;
    deflateTune(&strm, fuzz_int32_t_4, fuzz_int32_t_5, fuzz_int32_t_6, fuzz_int32_t_7);
  
    // inflateGetHeader
    gz_header header;
    inflateGetHeader(&strm, &header);
  
    // gzputc
    int c = 'c';
    gzputc(gz, c);
  
    // gzdirect
    int direct = gzdirect(gz);
  
    // adler32_combine
    uLong adler1 = 12345;
    uLong adler2 = 54321;
    off_t offset = 1024;
    uLong adler_result = adler32_combine(fuzz_uint64_t_8, fuzz_uint64_t_9, offset);
  
    // gzclose
    gzclose(gz);
  
    // Step 7: Release resources
    assert_file_closed(&in_file);;
    assert_file_closed(&out_file);;
  
    assert_file_name_closed("input_file");
	assert_file_name_closed("output_file");
	assert_file_closed(&out_file);
	assert_file_closed(&in_file);
	assert_fd_closed(out_fd);
	assert_fd_closed(in_fd);
	return 0;
}