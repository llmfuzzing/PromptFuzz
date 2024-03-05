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
//<ID> 955
//<Prompt> ["gzputs","deflateSetDictionary","zlibCompileFlags","gzread"]
/*<Combination>: [int gzputs(gzFile file, const char * s),
    int deflateSetDictionary(z_streamp strm, const Bytef * dictionary, uInt dictLength),
    uLong zlibCompileFlags(),
    int gzread(gzFile file, voidp buf, unsigned int len)
*/
//<score> 4, nr_unique_branch: 0
//<Quality> {"density":4,"unique_branches":{},"library_calls":["gzopen","gzread","gzclose","deflateSetDictionary","zlibCompileFlags","gzopen","gzputs","gzclose"],"critical_calls":["gzopen","gzread","gzclose","deflateSetDictionary","zlibCompileFlags","gzopen","gzputs","gzclose"],"visited":0}
/*Here is the C++ program that achieves the event using the zlib library APIs:

*/


extern "C" int LLVMFuzzerTestOneInput_49(const uint8_t* f_data, size_t f_size) {
	if(f_size<24) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytes(const uint8_t *, data, size, fdp)
		FDPConsumeRandomLengthString(char, fuzz_str_1, fuzz_str_sz_1, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_2, fuzz_str_sz_2, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_3, fuzz_str_sz_3, fdp);
	//fuzzer shim end}
	FILE *input_file_ptr = fopen("input_file", "wb");
	if (input_file_ptr == NULL) {return 0;}
	fwrite(data, sizeof(uint8_t), size, input_file_ptr);
	fclose(input_file_ptr);





    // Step 1: Read input data using gzread
    gzFile input_file = gzopen("input_file", fuzz_str_1);
    if (input_file == NULL) {
        assert_file_name_closed("input_file");
	return 0;
    }
    
    char input_buffer[1024];
    int read_size = gzread(input_file, input_buffer, sizeof(input_buffer));
    gzclose(input_file);
    
    // Step 2: Set dictionary using deflateSetDictionary
    z_stream strm;
    Bytef dictionary[1024];
    uInt dictLength = read_size;
    deflateSetDictionary(&strm, dictionary, dictLength);
    
    // Step 3: Get zlib compile flags using zlibCompileFlags
    uLong flags = zlibCompileFlags();
    
    // Step 4: Write output data using gzputs
    gzFile output_file = gzopen("output_file", fuzz_str_2);
    if (output_file == NULL) {
        assert_file_name_closed("output_file");
	assert_file_name_closed("input_file");
	return 0;
    }
    
    gzputs(output_file, fuzz_str_3);
    gzclose(output_file);
    
    assert_file_name_closed("output_file");
	assert_file_name_closed("input_file");
	return 0;
}