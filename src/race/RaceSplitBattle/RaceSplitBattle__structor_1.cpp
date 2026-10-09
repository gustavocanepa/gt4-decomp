typedef int s32;

struct Obj {
    char pad0[0x64];
    void *vtbl;
};

extern char RaceSplitBattle__vtable[];

extern "C" void DynamicsConductorBattle2P__structor_0(Obj *self, int flags);
extern "C" void RaceSplitDisplay__structor_1(void *self, int flags);
extern "C" void func_005C1628(void *p);

extern "C" void RaceSplitBattle__structor_1(Obj *self, int flags) {
    self->vtbl = RaceSplitBattle__vtable;
    RaceSplitDisplay__structor_1((char *)self + 0x26D80, 2);
    DynamicsConductorBattle2P__structor_0(self, 0);
    if (flags & 1) {
        return func_005C1628(self);
    }
}
