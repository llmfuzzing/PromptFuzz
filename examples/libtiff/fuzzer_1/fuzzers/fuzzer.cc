#include <tiffio.hxx>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <FuzzedDataProvider.h>


extern "C" int LLVMFuzzerTestOneInput_0(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_1(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_2(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_3(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_4(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_5(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_6(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_7(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_8(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_9(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_10(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_11(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_12(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_13(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_14(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_15(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_16(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_17(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_18(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_19(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_20(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_21(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_22(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_23(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_24(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_25(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_26(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_27(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_28(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_29(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_30(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_31(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_32(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_33(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_34(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_35(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_36(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_37(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_38(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_39(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_40(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_41(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_42(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_43(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_44(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_45(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_46(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_47(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_48(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_49(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_50(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_51(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_52(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_53(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_54(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_55(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_56(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_57(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_58(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_59(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_60(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_61(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_62(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_63(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_64(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_65(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_66(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_67(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_68(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_69(const uint8_t* data, size_t size);
extern "C" int LLVMFuzzerTestOneInput_70(const uint8_t* data, size_t size);


extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
	FuzzedDataProvider fdp(data, size);
	FDPConsumeIntegral(uint16_t, switch_id, fdp);
	const uint8_t *input = data + sizeof(uint16_t);
	size_t i_size = size - sizeof(uint16_t);
	switch (switch_id) {
		case 0:
			return LLVMFuzzerTestOneInput_0(input, i_size);
			break;
		case 1:
			return LLVMFuzzerTestOneInput_1(input, i_size);
			break;
		case 2:
			return LLVMFuzzerTestOneInput_2(input, i_size);
			break;
		case 3:
			return LLVMFuzzerTestOneInput_3(input, i_size);
			break;
		case 4:
			return LLVMFuzzerTestOneInput_4(input, i_size);
			break;
		case 5:
			return LLVMFuzzerTestOneInput_5(input, i_size);
			break;
		case 6:
			return LLVMFuzzerTestOneInput_6(input, i_size);
			break;
		case 7:
			return LLVMFuzzerTestOneInput_7(input, i_size);
			break;
		case 8:
			return LLVMFuzzerTestOneInput_8(input, i_size);
			break;
		case 9:
			return LLVMFuzzerTestOneInput_9(input, i_size);
			break;
		case 10:
			return LLVMFuzzerTestOneInput_10(input, i_size);
			break;
		case 11:
			return LLVMFuzzerTestOneInput_11(input, i_size);
			break;
		case 12:
			return LLVMFuzzerTestOneInput_12(input, i_size);
			break;
		case 13:
			return LLVMFuzzerTestOneInput_13(input, i_size);
			break;
		case 14:
			return LLVMFuzzerTestOneInput_14(input, i_size);
			break;
		case 15:
			return LLVMFuzzerTestOneInput_15(input, i_size);
			break;
		case 16:
			return LLVMFuzzerTestOneInput_16(input, i_size);
			break;
		case 17:
			return LLVMFuzzerTestOneInput_17(input, i_size);
			break;
		case 18:
			return LLVMFuzzerTestOneInput_18(input, i_size);
			break;
		case 19:
			return LLVMFuzzerTestOneInput_19(input, i_size);
			break;
		case 20:
			return LLVMFuzzerTestOneInput_20(input, i_size);
			break;
		case 21:
			return LLVMFuzzerTestOneInput_21(input, i_size);
			break;
		case 22:
			return LLVMFuzzerTestOneInput_22(input, i_size);
			break;
		case 23:
			return LLVMFuzzerTestOneInput_23(input, i_size);
			break;
		case 24:
			return LLVMFuzzerTestOneInput_24(input, i_size);
			break;
		case 25:
			return LLVMFuzzerTestOneInput_25(input, i_size);
			break;
		case 26:
			return LLVMFuzzerTestOneInput_26(input, i_size);
			break;
		case 27:
			return LLVMFuzzerTestOneInput_27(input, i_size);
			break;
		case 28:
			return LLVMFuzzerTestOneInput_28(input, i_size);
			break;
		case 29:
			return LLVMFuzzerTestOneInput_29(input, i_size);
			break;
		case 30:
			return LLVMFuzzerTestOneInput_30(input, i_size);
			break;
		case 31:
			return LLVMFuzzerTestOneInput_31(input, i_size);
			break;
		case 32:
			return LLVMFuzzerTestOneInput_32(input, i_size);
			break;
		case 33:
			return LLVMFuzzerTestOneInput_33(input, i_size);
			break;
		case 34:
			return LLVMFuzzerTestOneInput_34(input, i_size);
			break;
		case 35:
			return LLVMFuzzerTestOneInput_35(input, i_size);
			break;
		case 36:
			return LLVMFuzzerTestOneInput_36(input, i_size);
			break;
		case 37:
			return LLVMFuzzerTestOneInput_37(input, i_size);
			break;
		case 38:
			return LLVMFuzzerTestOneInput_38(input, i_size);
			break;
		case 39:
			return LLVMFuzzerTestOneInput_39(input, i_size);
			break;
		case 40:
			return LLVMFuzzerTestOneInput_40(input, i_size);
			break;
		case 41:
			return LLVMFuzzerTestOneInput_41(input, i_size);
			break;
		case 42:
			return LLVMFuzzerTestOneInput_42(input, i_size);
			break;
		case 43:
			return LLVMFuzzerTestOneInput_43(input, i_size);
			break;
		case 44:
			return LLVMFuzzerTestOneInput_44(input, i_size);
			break;
		case 45:
			return LLVMFuzzerTestOneInput_45(input, i_size);
			break;
		case 46:
			return LLVMFuzzerTestOneInput_46(input, i_size);
			break;
		case 47:
			return LLVMFuzzerTestOneInput_47(input, i_size);
			break;
		case 48:
			return LLVMFuzzerTestOneInput_48(input, i_size);
			break;
		case 49:
			return LLVMFuzzerTestOneInput_49(input, i_size);
			break;
		case 50:
			return LLVMFuzzerTestOneInput_50(input, i_size);
			break;
		case 51:
			return LLVMFuzzerTestOneInput_51(input, i_size);
			break;
		case 52:
			return LLVMFuzzerTestOneInput_52(input, i_size);
			break;
		case 53:
			return LLVMFuzzerTestOneInput_53(input, i_size);
			break;
		case 54:
			return LLVMFuzzerTestOneInput_54(input, i_size);
			break;
		case 55:
			return LLVMFuzzerTestOneInput_55(input, i_size);
			break;
		case 56:
			return LLVMFuzzerTestOneInput_56(input, i_size);
			break;
		case 57:
			return LLVMFuzzerTestOneInput_57(input, i_size);
			break;
		case 58:
			return LLVMFuzzerTestOneInput_58(input, i_size);
			break;
		case 59:
			return LLVMFuzzerTestOneInput_59(input, i_size);
			break;
		case 60:
			return LLVMFuzzerTestOneInput_60(input, i_size);
			break;
		case 61:
			return LLVMFuzzerTestOneInput_61(input, i_size);
			break;
		case 62:
			return LLVMFuzzerTestOneInput_62(input, i_size);
			break;
		case 63:
			return LLVMFuzzerTestOneInput_63(input, i_size);
			break;
		case 64:
			return LLVMFuzzerTestOneInput_64(input, i_size);
			break;
		case 65:
			return LLVMFuzzerTestOneInput_65(input, i_size);
			break;
		case 66:
			return LLVMFuzzerTestOneInput_66(input, i_size);
			break;
		case 67:
			return LLVMFuzzerTestOneInput_67(input, i_size);
			break;
		case 68:
			return LLVMFuzzerTestOneInput_68(input, i_size);
			break;
		case 69:
			return LLVMFuzzerTestOneInput_69(input, i_size);
			break;
		case 70:
			return LLVMFuzzerTestOneInput_70(input, i_size);
			break;
		default:
			break;
	}
return 0;
}
