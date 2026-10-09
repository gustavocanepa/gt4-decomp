typedef int s32;
typedef short s16;
typedef float f32;

struct VEntryI { s16 delta; s16 index; s32 (*fn)(void *); };
struct VEntryF { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline s32 vcall_i(char *o, s32 off) {
    VEntryI *e = (VEntryI *)(((VObj *)o)->vtbl + off);
    return e->fn(o + e->delta);
}
static inline f32 vcall_f(char *o, s32 off) {
    VEntryF *e = (VEntryF *)(((VObj *)o)->vtbl + off);
    return e->fn(o + e->delta);
}

struct Obj {
    char pad0[0xB0];
    char *b0;
    s32 b4;
    s32 b8;
    s32 bc;
};

extern "C" f32 func_0025B2B0(void *);
extern "C" void func_0025B2E0(s32, f32);
extern "C" f32 func_0025B310(void *);
extern "C" void func_0025B340(s32, f32);
extern "C" f32 func_0025B370(void *);
extern "C" void func_0025B3A0(s32, f32);
extern "C" f32 func_0025B3D0(void *);
extern "C" void func_0025B400(s32, f32);
extern "C" void func_002638E0(Obj *, s32, s32);
extern "C" s32 func_00265DC8(Obj *);
extern "C" void func_00265FF0(s32, s32);

extern "C" void func_002CFBE0(Obj *self, s32 arg1, s32 arg2) {
    f32 hi, lo, base, range, h2, l2;
    s32 mode;

    func_002638E0(self, arg1, 0);
    if (arg2 == 0) {
        return;
    }
    if (func_00265DC8(self) == 0) {
        return;
    }
    if (self->b0 == 0) {
        return;
    }
    if (self->b8 != 0) {
        func_00265FF0(self->b8, vcall_i(self->b0, 0x350));
    }
    if (self->bc != 0) {
        func_00265FF0(self->bc, vcall_i(self->b0, 0x358));
    }
    if (self->b4 != 0) {
        lo = vcall_f(self->b0, 0x340);
        hi = vcall_f(self->b0, 0x348);
        if (lo < 0.0f) {
            lo = 0.0f;
        }
        if (hi > 1.0f) {
            hi = 1.0f;
        }
        mode = *(s32 *)(self->b0 + 0xB0);
        if (mode == 1) {
            base = func_0025B310(self->b0);
        } else {
            base = func_0025B2B0(self->b0);
        }
        if (mode == 1) {
            range = func_0025B3D0(self->b0);
        } else {
            range = func_0025B370(self->b0);
        }
        h2 = hi * range;
        l2 = base + lo * range;
        switch (mode) {
        case 1:
            func_0025B340(self->b4, l2);
            func_0025B400(self->b4, h2);
            return;
        case 0:
            func_0025B2E0(self->b4, l2);
            func_0025B3A0(self->b4, h2);
            return;
        }
    }
}
