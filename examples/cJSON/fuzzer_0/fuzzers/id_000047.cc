#include "FDSan.h"
#include <cJSON.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
//<ID> 1561
//<Prompt> ["cJSON_Compare","cJSON_ReplaceItemInObjectCaseSensitive","cJSON_GetNumberValue","cJSON_AddBoolToObject","cJSON_InsertItemInArray"]
/*<Combination>: [cJSON_bool cJSON_Compare(const cJSON *const a, const cJSON *const b, const cJSON_bool case_sensitive),
    cJSON_bool cJSON_ReplaceItemInObjectCaseSensitive(cJSON * object, const char * string, cJSON * newitem),
    double cJSON_GetNumberValue(const cJSON *const item),
    cJSON *cJSON_AddBoolToObject(cJSON *const object, const char *const name, const cJSON_bool boolean),
    cJSON_bool cJSON_InsertItemInArray(cJSON * array, int which, cJSON * newitem)
*/
//<score> 24, nr_unique_branch: 1
//<Quality> {"density":12,"unique_branches":{"print_number":[[77,18,77,26,2,0,4,0]]},"library_calls":["cJSON_Parse","cJSON_GetObjectItem","cJSON_GetObjectItem","cJSON_GetObjectItem","cJSON_GetNumberValue","cJSON_GetNumberValue","cJSON_DeleteItemFromObjectCaseSensitive","cJSON_DeleteItemFromObjectCaseSensitive","cJSON_AddNumberToObject","cJSON_Print","cJSON_Delete","cJSON_Delete"],"critical_calls":["cJSON_Parse","cJSON_GetObjectItem","cJSON_GetObjectItem","cJSON_GetObjectItem","cJSON_GetNumberValue","cJSON_GetNumberValue","cJSON_DeleteItemFromObjectCaseSensitive","cJSON_DeleteItemFromObjectCaseSensitive","cJSON_AddNumberToObject","cJSON_Print","cJSON_Delete"],"visited":0}
/**/


extern "C" int LLVMFuzzerTestOneInput_47(const uint8_t *data, size_t size) {
	if(size<0) return 0;

    // Create a file stream to read the input data
    FILE *in_file = fmemopen((void *)data, size, "rb");
    if (in_file == NULL) {
        assert_file_closed(&in_file);
	return 0;
    }

    // Read the input data from the file stream
    char input_data[size + 1];
    memset(input_data, 0, sizeof(input_data));
    fread(input_data, sizeof(char), size, in_file);

    // Close the file stream
    assert_file_closed(&in_file);;

    // Parse the input data using cJSON_Parse
    cJSON *root = cJSON_Parse(input_data);
    if (root == NULL) {
        assert_file_closed(&in_file);
	return 0;
    }

    // Perform event by using cJSON APIs
    cJSON *imageObj = cJSON_GetObjectItem(root, "Image");
    if (imageObj != NULL) {
        cJSON *widthObj = cJSON_GetObjectItem(imageObj, "Width");
        cJSON *heightObj = cJSON_GetObjectItem(imageObj, "Height");
        if (widthObj != NULL && heightObj != NULL) {
            double width = cJSON_GetNumberValue(widthObj);
            double height = cJSON_GetNumberValue(heightObj);
            double area = width * height;
            cJSON_DeleteItemFromObjectCaseSensitive(imageObj, "Width");
            cJSON_DeleteItemFromObjectCaseSensitive(imageObj, "Height");
            cJSON_AddNumberToObject(imageObj, "Area", area);
        }
    }

    // Serialize the modified cJSON object
    char *output_data = cJSON_Print(root);

    // Open output file to write the serialized data
    FILE *out_file = fopen("output_file", "wb");
    if (out_file == NULL) {
        cJSON_Delete(root);
        free(output_data);
        assert_file_closed(&out_file);
	assert_file_closed(&in_file);
	return 0;
    }

    // Write the serialized data to the file
    fwrite(output_data, sizeof(char), strlen(output_data), out_file);

    // Close the output file
    assert_file_closed(&out_file);;

    // Free allocated memory
    cJSON_Delete(root);
    free(output_data);

    assert_file_closed(&out_file);
	assert_file_closed(&in_file);
	return 0;
}