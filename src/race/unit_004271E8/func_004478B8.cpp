typedef int s32;
typedef long long s64;
typedef unsigned long long u64;

extern s32 D_0062380C;
extern "C" s32 SPEC_DATABASE__DatabaseTable__getRow(s32, s32, s32);

extern "C" s32 func_004478B8(u64 id, s32 x) {
    return SPEC_DATABASE__DatabaseTable__getRow(D_0062380C, (s32)(id & 0xFFFFFFFF), x) != 0;
}
