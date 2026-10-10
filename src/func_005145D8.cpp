typedef int s32;

extern "C" s32 (*D_008A0590)(s32, s32);
extern "C" s32 D_008A0368;

extern "C" s32 func_005145D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*temp_v1)(s32, s32) = D_008A0590;

    if (temp_v1 != 0) {
        temp_v1(arg3, D_008A0368);
    }
    return 0x18;
}
