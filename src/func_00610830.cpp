struct Req {
    int handle;
    char pad[0x3C];
    int arg0;
    int arg1;
    int arg2;
};
extern "C" void func_00578500(int);
extern "C" int func_00578168(void *obj, int a1, int a2, void *buf, int size);
extern "C" int func_00610830(Req *r, int a1, int a2) {
    char raw[0x80];
    func_00578500(r->handle);
    r->arg0 = a1;
    int *buf = (int *)(((unsigned int)raw + 0x3F) & ~0x3F);
    r->arg1 = a2;
    func_00578168(r, 1, 0, buf, 0x40);
    return buf[0];
}
