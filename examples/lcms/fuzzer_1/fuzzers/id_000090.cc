#include "FDSan.h"
#include "FuzzedDataProvider.h"
#include <lcms2.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <iostream>
//<ID> 10800
//<Prompt> ["cmsFormatterForPCSOfProfile","cmsSetHeaderFlags","cmsDictFree","cmsDupNamedColorList","cmsFreeToneCurveTriple"]
/*<Combination>: [cmsUInt32Number cmsFormatterForPCSOfProfile(cmsHPROFILE hProfile, cmsUInt32Number nBytes, cmsBool lIsFloat),
    void cmsSetHeaderFlags(cmsHPROFILE hProfile, cmsUInt32Number Flags),
    void cmsDictFree(cmsHANDLE hDict),
    cmsNAMEDCOLORLIST *cmsDupNamedColorList(const cmsNAMEDCOLORLIST * v),
    void cmsFreeToneCurveTriple(cmsToneCurve Curve[3])
*/
//<score> 4.4, nr_unique_branch: 5, p_cov: 0.8
//<Quality> {"diversity":12,"density":11,"covered_api":["cmsSetHeaderFlags","cmsDictFree","cmsDupNamedColorList","cmsFreeToneCurveTriple"],"uncovered_api":["cmsFormatterForPCSOfProfile"],"unique_branches":{"cmsDupNamedColorList":[[593,12,593,45,0],[594,13,594,39,1]],"cmsFreeToneCurveTriple":[[955,9,955,25,1],[956,9,956,25,1],[957,9,957,25,1]]},"library_calls":["cmsCreateContext","cmsCreateNULLProfileTHR","cmsAllocNamedColorList","cmsSetHeaderFlags","cmsDupNamedColorList","cmsFreeToneCurveTriple","cmsDictAlloc","cmsDictFree","cmsCloseProfile","cmsFreeNamedColorList","cmsFreeNamedColorList","cmsDeleteContext"]}
/**/

extern "C" int LLVMFuzzerTestOneInput_90(const uint8_t* f_data, size_t f_size) {
	if(f_size<=16) return 0;

	
	//fuzzer vars shim {
		FuzzedDataProvider fdp(f_data, f_size);
		FDPConsumeRawBytes(const uint8_t *, data, size, fdp)
		FDPConsumeRandomLengthString(char, fuzz_str_1, fuzz_str_sz_1, fdp);
		FDPConsumeRandomLengthString(char, fuzz_str_2, fuzz_str_sz_2, fdp);
		FDPConsumeIntegral(uint32_t, fuzz_uint32_t_3, fdp);
	//fuzzer shim end}




    // Create a context
    cmsContext context = cmsCreateContext(NULL, NULL);

    // Create a handle for the profile
    cmsHPROFILE profile = cmsCreateNULLProfileTHR(context);

    // Create a named color list
    cmsNAMEDCOLORLIST *namedColorList = cmsAllocNamedColorList(context, 10, 3, fuzz_str_1, fuzz_str_2);

    // Set the profile header flags
    cmsSetHeaderFlags(profile, fuzz_uint32_t_3);

    // Duplicate the named color list
    cmsNAMEDCOLORLIST *duplicatedList = cmsDupNamedColorList(namedColorList);

    // Free the tone curve triple
    cmsToneCurve *toneCurves[3];
    cmsFreeToneCurveTriple(toneCurves);

    // Dictionary
    cmsHANDLE dictionary = cmsDictAlloc(context);

    // Free the dictionary
    cmsDictFree(dictionary);

    // Release all allocated resources
    cmsCloseProfile(profile);
    cmsFreeNamedColorList(namedColorList);
    cmsFreeNamedColorList(duplicatedList);
    cmsDeleteContext(context);

    return 0;
}