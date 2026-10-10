/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long long s64;

struct Obj {
    void *f0;
    s32 f4;
    s64 f8;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
};

extern char D_006518C8[];

extern "C" void func_0055CFE8(Obj *self, s64 id) {
    self->f0 = D_006518C8;
    self->f30 = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f18 = 0;
    self->f1C = 0;
    self->f20 = -1;
    self->f24 = -1;
    self->f28 = -1;
    self->f2C = -1;
    self->f8 = id;
}
