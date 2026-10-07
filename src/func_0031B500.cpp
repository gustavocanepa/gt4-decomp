extern "C" void func_0031B5B8(int arg0);
extern "C" int func_00326750(int arg0, int arg1, char *arg2);
extern char D_0069E298[];
extern int D_00619E30;

extern "C" int func_0031B500(int arg0)
{
    if (arg0 == 0) {
        D_00619E30 = 0;
    } else if (D_00619E30 == 0) {
        int s0 = func_00326750(8, 4, D_0069E298);
        func_0031B5B8(s0);
        D_00619E30 = s0;
    }
    return D_00619E30;
}
