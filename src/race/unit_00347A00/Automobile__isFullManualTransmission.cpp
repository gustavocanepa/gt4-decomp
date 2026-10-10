typedef unsigned char u8;
typedef int s32;

struct S { char pad[0x546]; u8 unk546; };

extern "C" s32 Automobile__isFullManualTransmission(S *arg0) {
    return arg0->unk546 == 6;
}
