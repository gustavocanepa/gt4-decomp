typedef int s32;

extern s32 D_0064A308;
extern s32 D_008A03B8;
extern s32 D_008A0190;

extern "C" s32 func_0050D4D8(s32 arg0, s32 arg1) {
    if (D_0064A308 != 1) {
        return -0xF;
    }
    D_008A03B8 = arg0;
    D_008A0190 = arg1;
    return 0;
}
