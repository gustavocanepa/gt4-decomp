typedef int s32;

struct Obj {
    char pad0[0xC];
    void *vtbl;
};

extern char D_006233D8[];
extern char D_006881A0[];

extern "C" void *func_004383D8(Obj *self, void *def);

extern "C" void *func_0043C310(Obj *self, void *def) {
    if (def == 0) {
        def = D_006233D8;
    }
    void *r = func_004383D8(self, def);
    self->vtbl = D_006881A0;
    return r;
}
