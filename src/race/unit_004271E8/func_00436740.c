typedef int s32;
extern char D_006184D0[];
void func_001074D0(char *a, s32 b, s32 c, s32 d, s32 e);
void func_004AB040(s32 a);
s32 func_00436740(char *arg0) {
    func_001074D0(D_006184D0, 1, 0, 0x280, 0x1C0);
    func_004AB040(0x17);
    return *(s32 *)(arg0 + 0x16B0) != 0;
}
