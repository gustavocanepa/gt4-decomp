extern "C" void func_002ED5A8(void *obj, int arg1);
extern "C" void func_001467E8(void *obj, const char *name, int arg2);
extern "C" void func_002ED5C0(int obj, int arg1);

extern "C" char D_00146860[];

extern "C" void func_00146D80(int arg0, int arg1) {
    char buf[0x10];
    int s1 = arg0;
    int s0 = arg1;
    func_002ED5A8(buf, s1);
    func_001467E8(buf, D_00146860, s0);
    func_002ED5C0(s1, 2);
}
