typedef int s32;

extern "C" s32 (*D_008A0424)(s32, s32);
extern "C" s32 D_008A01FC;

extern "C" s32 func_00512AF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*temp_v1)(s32, s32) = D_008A0424;

    if (temp_v1 != 0) {
        temp_v1(arg3, D_008A01FC);
    }
    return 0x80;
}
