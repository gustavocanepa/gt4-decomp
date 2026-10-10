struct Req {
    int handle;
    char pad[0x3C];
    int arg0;
    int arg1;
    int arg2;
};
extern "C" void func_00578500(int);
extern "C" int func_00578168(void *obj, int a1, int a2, void *buf, int size);
extern Req D_008735C0;
extern "C" void func_0055E878(int a0, int a1, int a2) {
    func_00578500(D_008735C0.handle);
    D_008735C0.arg0 = a0;
    D_008735C0.arg1 = a1;
    D_008735C0.arg2 = a2;
    func_00578168(&D_008735C0, 5, 1, 0, 0);
}
