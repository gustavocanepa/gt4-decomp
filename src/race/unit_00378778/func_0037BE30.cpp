typedef int s32;

struct Obj {
    void *vtbl;
    char pad[0x18C];
    s32 a190;
    s32 pad194;
    s32 a198;
    char pad19c[0xC];
    s32 a1a8;
};

extern char D_0067A758[];
extern "C" Obj *func_00378AE0(Obj *);

extern "C" Obj *func_0037BE30(Obj *self) {
    Obj *r = func_00378AE0(self);
    self->vtbl = D_0067A758;
    self->a190 = 0;
    self->a198 = 0;
    self->a1a8 = 0;
    return r;
}
