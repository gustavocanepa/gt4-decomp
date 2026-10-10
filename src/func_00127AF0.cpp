typedef int s32;

struct Mgr {
    char pad[0x448];
    void *items[3];
};

extern Mgr *D_006187A8;
extern "C" void func_0042E478(void *, s32, s32);

extern "C" void func_00127AF0(void *arg0, s32 idx, s32 a, s32 b) {
    Mgr *m = D_006187A8;
    if (m != 0 && idx < 3)
        func_0042E478(m->items[idx], a, b);
}
