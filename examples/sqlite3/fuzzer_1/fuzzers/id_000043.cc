#include "FDSan.h"
#include "FuzzedDataProvider.h"
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
//<ID> 1183
//<Prompt> ["sqlite3_open","sqlite3_prepare_v2","sqlite3_bind_parameter_count","sqlite3_bind_zeroblob64","sqlite3_bind_pointer","sqlite3_bind_double","sqlite3_step","sqlite3_finalize","sqlite3_close"]
/*<Combination>: [int sqlite3_open(const char * filename, sqlite3 ** ppDb),
    int sqlite3_prepare_v2(sqlite3 * db, const char * zSql, int nByte, sqlite3_stmt ** ppStmt, const char ** pzTail),
    int sqlite3_bind_parameter_count(sqlite3_stmt * ),
    int sqlite3_bind_zeroblob64(sqlite3_stmt * , int , sqlite3_uint64 ),
    int sqlite3_bind_pointer(sqlite3_stmt * , int , void * , const char * , void (*)(void *) ),
    int sqlite3_bind_double(sqlite3_stmt * , int , double ),
    int sqlite3_step(sqlite3_stmt * ),
    int sqlite3_finalize(sqlite3_stmt * pStmt),
    int sqlite3_close(sqlite3 * )
*/
//<score> 2, nr_unique_branch: 1, p_cov: 1
//<Quality> {"diversity":10,"density":10,"covered_api":["sqlite3_open","sqlite3_prepare_v2","sqlite3_bind_parameter_count","sqlite3_bind_zeroblob64","sqlite3_bind_pointer","sqlite3_bind_double","sqlite3_step","sqlite3_finalize","sqlite3_close"],"uncovered_api":[],"unique_branches":{"sqlite3_bind_double":[[90840,7,90840,20,0]]},"library_calls":["sqlite3_open","sqlite3_prepare_v2","sqlite3_bind_parameter_count","sqlite3_bind_zeroblob64","sqlite3_bind_double","sqlite3_bind_pointer","sqlite3_step","sqlite3_finalize","sqlite3_close"]}
/*Here is the completed C++ program that achieves the event using the sqlite3 APIs:

*/


extern "C" int LLVMFuzzerTestOneInput_43(const uint8_t* f_data, size_t f_size) {
	if(f_size<=27) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytes(const uint8_t *, data, size, fdp)
		FDPConsumeIntegral(int32_t, fuzz_int32_t_1, fdp);
		FDPConsumeIntegral(uint64_t, fuzz_uint64_t_2, fdp);
		FDPConsumeIntegral(int32_t, fuzz_int32_t_3, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_4, fuzz_str_sz_4, fdp);
		FDPConsumeIntegral(int32_t, fuzz_int32_t_5, fdp);
	//fuzzer shim end}




    // Open a database connection
    sqlite3 *db;
    if (sqlite3_open(":memory:", &db) != SQLITE_OK) {
        return 0;
    }

    // Create a prepared statement
    sqlite3_stmt *stmt;
    const char *tail;
    if (sqlite3_prepare_v2(db, (const char *)data, size, &stmt, &tail) != SQLITE_OK) {
        sqlite3_close(db);
        return 0;
    }

    // Bind parameters
    int paramCount = sqlite3_bind_parameter_count(stmt);
    for (int i = 1; i <= paramCount; i++) {
        sqlite3_bind_zeroblob64(stmt, fuzz_int32_t_1, fuzz_uint64_t_2);
        sqlite3_bind_double(stmt, fuzz_int32_t_3, 3.14);
        sqlite3_bind_pointer(stmt, fuzz_int32_t_5, NULL, fuzz_str_4, NULL);
    }

    // Execute the statement
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // Process each row of the result
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

    // Close the database connection
    sqlite3_close(db);

    return 0;
}