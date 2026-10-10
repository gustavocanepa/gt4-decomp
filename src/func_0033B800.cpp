typedef int s32;

struct Obj {
    s32 a;
    s32 b;
    void *p;
    char pad[0x14];
    void *vtbl;
    char buf[4];
};

extern char D_00679880[];
extern "C" void func_003B6C10(Obj *);

extern "C" void func_0033B800(Obj *self) {
    func_003B6C10(self);
    self->vtbl = D_00679880;
    self->b = 6;
    self->p = self->buf;
}
