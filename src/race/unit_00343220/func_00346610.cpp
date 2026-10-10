extern "C" void *func_00578CB0(int size);
extern "C" void *func_005A48D8(void *p, int c, int n);

extern void *D_00620238;
extern int D_0062023C;
extern int D_00620240;

extern "C" void func_00346610(int w, int h) {
    int size = w * h;
    void *p = func_00578CB0(size);
    D_00620238 = p;
    D_0062023C = w;
    D_00620240 = h;
    func_005A48D8(p, 0, size);
}
