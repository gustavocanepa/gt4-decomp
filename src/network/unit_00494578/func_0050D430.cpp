typedef int s32;

extern s32 D_0064A308;
extern s32 D_008A0424;
extern s32 D_008A01FC;

extern "C" s32 func_0050D430(s32 arg0, s32 arg1) {
    if (D_0064A308 != 1) {
        return -0xF;
    }
    D_008A0424 = arg0;
    D_008A01FC = arg1;
    return 0;
}
