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
//<ID> 94
//<Prompt> ["cJSON_DetachItemFromObjectCaseSensitive","cJSON_IsNull","cJSON_IsArray","cJSON_AddStringToObject","cJSON_DetachItemFromObject","cJSON_DetachItemFromArray","cJSON_PrintPreallocated"]
/*<Combination>: [cJSON *cJSON_DetachItemFromObjectCaseSensitive(cJSON * object, const char * string),
    cJSON_bool cJSON_IsNull(const cJSON *const item),
    cJSON_bool cJSON_IsArray(const cJSON *const item),
    cJSON *cJSON_AddStringToObject(cJSON *const object, const char *const name, const char *const string),
    cJSON *cJSON_DetachItemFromObject(cJSON * object, const char * string),
    cJSON *cJSON_DetachItemFromArray(cJSON * array, int which),
    cJSON_bool cJSON_PrintPreallocated(cJSON * item, char * buffer, const int length, const cJSON_bool format)
*/
//<score> 78, nr_unique_branch: 5
//<Quality> {"density":13,"unique_branches":{"get_array_item":[[1855,9,1855,22,0,0,4,0]],"cJSON_AddStringToObject":[[2142,9,2142,76,0,0,4,1]],"print_value":[[1371,9,1371,23,0,0,4,0]],"cJSON_DetachItemViaPointer":[[2189,9,2189,25,0,0,4,0]],"add_item_to_object":[[2016,9,2016,25,0,0,4,0]]},"library_calls":["cJSON_Parse","cJSON_DetachItemFromObjectCaseSensitive","cJSON_IsNull","cJSON_IsArray","cJSON_AddStringToObject","cJSON_DetachItemFromObject","cJSON_GetObjectItem","cJSON_DetachItemFromArray","cJSON_PrintPreallocated","cJSON_Delete","cJSON_Delete","cJSON_Delete","cJSON_Delete"],"critical_calls":["cJSON_Parse","cJSON_DetachItemFromObjectCaseSensitive","cJSON_IsNull","cJSON_IsArray","cJSON_AddStringToObject","cJSON_DetachItemFromObject","cJSON_GetObjectItem","cJSON_DetachItemFromArray","cJSON_PrintPreallocated","cJSON_Delete","cJSON_Delete","cJSON_Delete","cJSON_Delete"],"visited":0}
/**/

extern "C" int LLVMFuzzerTestOneInput_7(const uint8_t* f_data, size_t f_size) {
	if(f_size<57) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytesWithNullTerm(const uint8_t *, data, size, fdp)
		FDPConsumeRandomLengthString(char, fuzz_str_1, fuzz_str_sz_1, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_2, fuzz_str_sz_2, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_3, fuzz_str_sz_3, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_4, fuzz_str_sz_4, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_5, fuzz_str_sz_5, fdp);
		FDPConsumeIntegral(int32_t, fuzz_int32_t_6, fdp);
	//fuzzer shim end}




    // Create a null-terminated string from the input data
    char* input = new char[size + 1];
    memcpy(input, data, size);
    input[size] = '\0';

    // Create a cJSON object from the input string
    cJSON* root = cJSON_Parse(input);

    // Detach an item from the cJSON object
    cJSON* item = cJSON_DetachItemFromObjectCaseSensitive(root, fuzz_str_1);

    // Check if the detached item is null
    cJSON_bool isNull = cJSON_IsNull(item);

    // Check if the detached item is an array
    cJSON_bool isArray = cJSON_IsArray(item);

    // Add a string to the cJSON object
    cJSON_AddStringToObject(root, fuzz_str_2, fuzz_str_3);

    // Detach an item from the cJSON object by string
    cJSON* itemToRemove = cJSON_DetachItemFromObject(root, fuzz_str_4);

    // Detach an item from a cJSON array
    cJSON* array = cJSON_GetObjectItem(root, fuzz_str_5);
    cJSON* arrayItem = cJSON_DetachItemFromArray(array, fuzz_int32_t_6);

    // Create a buffer to store the printed cJSON object
    const int bufferSize = 1024;
    char buffer[bufferSize];

    // Print the cJSON object to the buffer
    cJSON_PrintPreallocated(root, buffer, bufferSize, true);

    // Free the cJSON object and the detached items
    cJSON_Delete(root);
    cJSON_Delete(item);
    cJSON_Delete(itemToRemove);
    cJSON_Delete(arrayItem);

    // Delete the input string
    delete[] input;

    return 0;
}