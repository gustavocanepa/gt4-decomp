struct Req {
    int handle;
    char pad[0x3C];
    int arg0;
    int arg1;
    int arg2;
};
extern Req D_0086F800;

extern "C" void func_00578500(int);
extern "C" int func_00578168(void *obj, int a1, int a2, void *buf, int size);

extern "C" void func_00550DE8(int a0, int a1, int a2) {
    func_00578500(D_0086F800.handle);
    D_0086F800.arg0 = a0;
    D_0086F800.arg1 = a1;
    D_0086F800.arg2 = a2;
    func_00578168(&D_0086F800, 5, 0, 0, 0);
}
