typedef int s32;

struct Sub_00548850 {
    char data[8];
    s32 m8;
    s32 mC;
};

struct Global_00548850 {
    char pad0[0x80];
    Sub_00548850 m80;
};

extern "C" Global_00548850 D_0086CC80;
extern "C" void func_00576AD8(Sub_00548850 *p, s32 n);

extern "C" void func_00548850(s32 *arg0, s32 *arg1) {
    Global_00548850 *g = &D_0086CC80;
    func_00576AD8(&g->m80, 0x40);
    *arg0 = g->m80.m8;
    *arg1 = g->m80.mC;
}
