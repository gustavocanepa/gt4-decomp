extern "C" int func_00591A78(int arg0, long long *out0, int *out1);

extern "C" int func_00591FC8(int arg0, long long *arg1) {
    long long buf0;
    int buf1;
    int s0 = arg0;

    if (func_00591A78(arg0, &buf0, &buf1) != 0) {
        if (buf1 != 0) {
            buf0 = -buf0;
        }
        *arg1 = buf0;
    }
    return s0;
}
