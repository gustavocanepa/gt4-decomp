typedef int s32;

extern "C" s32 (*D_008A0478)(s32, s32);
extern "C" s32 D_008A0250;

extern "C" s32 func_00513608(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*temp_v1)(s32, s32) = D_008A0478;

    if (temp_v1 != 0) {
        temp_v1(arg3, D_008A0250);
    }
    return 0x20;
}
