typedef int s32;

extern "C" s32 func_00106298(char *arg0);
extern "C" s32 func_001062B8(char *arg0);
extern "C" char D_006184D0[];

extern "C" void func_002160A0(void *arg0, s32 *arg1, s32 *arg2) {
    char *p = D_006184D0;
    *arg1 = func_00106298(p);
    *arg2 = func_001062B8(p);
}
