struct Req {
    int handle;
    char pad[0x3C];
    int arg0;
    int arg1;
    int arg2;
};
extern "C" void func_00578500(int);
extern "C" int func_00578168(void *obj, int a1, int a2, void *buf, int size);
extern Req D_0086F8C0;
extern "C" int func_00551240(int a0, int a1) {
    char raw[0x80];
    func_00578500(D_0086F8C0.handle);
    D_0086F8C0.arg0 = a0;
    int *buf = (int *)(((unsigned int)raw + 0x3F) & ~0x3F);
    D_0086F8C0.arg1 = a1;
    func_00578168(&D_0086F8C0, 1, 0, buf, 0x40);
    return buf[0];
}
