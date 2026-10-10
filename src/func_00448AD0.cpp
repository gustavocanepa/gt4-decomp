extern "C" int func_00447BB8(int a, int b);
extern "C" int func_00447C28(int a);
extern "C" int func_00448B48(int i, int b);

extern "C" int func_00448AD0(int a, int b) {
    int i = func_00447BB8(a, b);
    if (i == -1) {
        i = func_00447C28(a);
        if (i == -1)
            return 0;
    }
    return func_00448B48(i, b);
}
