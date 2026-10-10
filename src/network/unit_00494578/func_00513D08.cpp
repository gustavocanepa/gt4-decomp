typedef int s32;

extern "C" s32 (*D_008A056C)(s32, s32);
extern "C" s32 D_008A0344;

extern "C" s32 func_00513D08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*temp_v1)(s32, s32) = D_008A056C;

    if (temp_v1 != 0) {
        temp_v1(arg3, D_008A0344);
    }
    return 0x1FC;
}
