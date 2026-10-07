extern char D_0086C8D8;

struct S_86C8E0 {
    char pad[0x30];
    char f0;
    char f1;
    char f2;
    char f3;
    char f4;
    char f5;
};
extern S_86C8E0 D_0086C8E0;

extern "C" void func_00576100(void *arg0);
extern "C" void func_00576140(void *arg0);
extern "C" void func_00574EE8(void *arg0);

extern "C" void func_00547900(void) {
    void * volatile sp0 = &D_0086C8D8;
    func_00576100(&D_0086C8D8);

    D_0086C8E0.f0 = 1;
    D_0086C8E0.f3 = 1;
    D_0086C8E0.f1 = 0;
    D_0086C8E0.f4 = 0;
    D_0086C8E0.f5 = 0;

    func_00576140(sp0);
    func_00574EE8(&D_0086C8E0);
}
