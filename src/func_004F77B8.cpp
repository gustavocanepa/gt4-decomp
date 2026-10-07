typedef int s32;

struct Pair {
    void *p;
    s32 n;
};

extern char D_00645570[];
extern char D_006C0888[];

extern "C" void func_004F0B08(void *arg0, s32 arg1);
extern "C" s32 func_004F0C38(void *arg0, const char *arg1);
extern "C" void func_004F8900(void *arg0, void *arg1);

extern "C" void func_004F77B8(void *arg0, void *arg1, void *arg2) {
    Pair g;
    if (arg2 == 0) {
        arg2 = D_00645570;
    }
    g.p = arg2;
    g.n = 0;
    if (func_004F0C38(arg2, D_006C0888) != 0) {
        func_004F0B08(g.p, g.n);
        return;
    }
    func_004F8900(arg2, arg0);
    func_004F0B08(g.p, g.n);
}
