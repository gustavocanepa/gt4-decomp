typedef int s32;

struct Obj {
    char pad0[0x4C];
    void *vtbl;
    s32 pad50;
    void *buf54;
    char pad58[0x154 - 0x58];
    void *buf154;
};

void func_001CC060(struct Obj *, s32);
void func_00575DA0(void *);
void func_005C1628(void *);

extern char D_006611F0[];
extern char D_006614F8[];
extern char D_00661758[];

void func_005D1D08(struct Obj *self, s32 flags) {
    self->vtbl = D_00661758;
    if (self->buf154 != 0) {
        func_00575DA0(self->buf154);
    }
    self->vtbl = D_006611F0;
    if (self->buf54 != 0) {
        func_00575DA0(self->buf54);
    }
    self->vtbl = D_006614F8;
    func_001CC060(self, 0);
    if (flags & 1) {
        func_005C1628(self);
    }
}
