typedef int s32;

struct Obj {
    char pad0[0x64];
    void *vtbl;
};

extern char D_00676C48[];

extern "C" void func_0032F238(Obj *self, int flags);
extern "C" void func_003A3070(void *self, int flags);
extern "C" void func_005C1628(void *p);

extern "C" void func_003305D0(Obj *self, int flags) {
    self->vtbl = D_00676C48;
    func_003A3070((char *)self + 0x26D80, 2);
    func_0032F238(self, 0);
    if (flags & 1) {
        return func_005C1628(self);
    }
}
