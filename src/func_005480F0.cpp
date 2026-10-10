struct Req {
    int handle;
    char pad[0x3C];
    int arg0;
    int arg1;
    int arg2;
};
extern "C" void func_00578500(int);
extern "C" int func_00578168(void *obj, int a1, int a2, void *buf, int size);
extern Req D_0086CA40;
extern "C" void func_005480F0(float x) {
    float lo = 0.0f;
    float hi = 1.0f;
    if (x < lo)
        x = lo;
    if (hi < x)
        x = hi;
    int v = (int)(x * 32768.0f);
    func_00578500(D_0086CA40.handle);
    D_0086CA40.arg0 = v;
    func_00578168(&D_0086CA40, 5, 0, 0, 0);
}
