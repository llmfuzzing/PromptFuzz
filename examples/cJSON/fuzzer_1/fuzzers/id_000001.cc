#include "FDSan.h"
#include "FuzzedDataProvider.h"
#include <cJSON.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
//<ID> 30
//<Prompt> ["cJSON_AddItemReferenceToArray","cJSON_Version","cJSON_CreateTrue","cJSON_CreateDoubleArray","cJSON_AddRawToObject","cJSON_CreateIntArray","cJSON_AddFalseToObject","cJSON_SetValuestring"]
/*<Combination>: [cJSON_bool cJSON_AddItemReferenceToArray(cJSON * array, cJSON * item),
    const char *cJSON_Version(),
    cJSON *cJSON_CreateTrue(),
    cJSON *cJSON_CreateDoubleArray(const double * numbers, int count),
    cJSON *cJSON_AddRawToObject(cJSON *const object, const char *const name, const char *const raw),
    cJSON *cJSON_CreateIntArray(const int * numbers, int count),
    cJSON *cJSON_AddFalseToObject(cJSON *const object, const char *const name),
    char *cJSON_SetValuestring(cJSON * object, const char * valuestring)
*/
//<score> 26, nr_unique_branch: 1
//<Quality> {"density":13,"unique_branches":{"add_item_to_array":[[1960,9,1960,23,0,0,4,0]]},"library_calls":["cJSON_CreateObject","cJSON_AddItemToArray","cJSON_CreateTrue","cJSON_AddItemToArray","cJSON_CreateDoubleArray","cJSON_AddRawToObject","cJSON_AddItemToArray","cJSON_CreateIntArray","cJSON_AddFalseToObject","cJSON_SetValuestring","cJSON_Print","cJSON_Delete","cJSON_free"],"critical_calls":["cJSON_CreateObject","cJSON_AddItemToArray","cJSON_CreateTrue","cJSON_AddItemToArray","cJSON_CreateDoubleArray","cJSON_AddRawToObject","cJSON_AddItemToArray","cJSON_CreateIntArray","cJSON_AddFalseToObject","cJSON_SetValuestring","cJSON_Print","cJSON_Delete","cJSON_free"],"visited":0}
/**/


extern "C" int LLVMFuzzerTestOneInput_1(const uint8_t* f_data, size_t f_size) {
	if(f_size<30) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytesWithNullTerm(const uint8_t *, data, size, fdp)
		FDPConsumeRandomLengthString(char, fuzz_str_1, fuzz_str_sz_1, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_2, fuzz_str_sz_2, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_3, fuzz_str_sz_3, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_4, fuzz_str_sz_4, fdp);
	//fuzzer shim end}




    // Create a cJSON object
    cJSON *root = cJSON_CreateObject();

    // Add items to the cJSON object
    cJSON_AddItemToArray(root, cJSON_CreateTrue());
    cJSON_AddItemToArray(root, cJSON_CreateDoubleArray(nullptr, 0));
    cJSON_AddRawToObject(root, fuzz_str_1, fuzz_str_2);
    cJSON_AddItemToArray(root, cJSON_CreateIntArray(nullptr, 0));
    cJSON_AddFalseToObject(root, fuzz_str_3);
    cJSON_SetValuestring(root, fuzz_str_4);

    // Print the cJSON object to a string
    char *jsonString = cJSON_Print(root);
    cJSON_Delete(root);

    // Write the cJSON object string to a file
    FILE *outFile = fopen("output_file", "wb");
    if (outFile) {
        fwrite(jsonString, sizeof(char), strlen(jsonString), outFile);
        assert_file_closed(&outFile);;
    }

    // Free allocated memory
    cJSON_free(jsonString);

    assert_file_closed(&outFile);
	return 0;
}