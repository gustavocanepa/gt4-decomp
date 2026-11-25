typedef int s32;
typedef short s16;
typedef float f32;

struct Obj { char pad0[4]; char *vtbl; };
struct VEntry { s16 delta; s16 index; f32 (*fn)(void *); };
struct H { void *p; };

extern "C" void func_00236680(H *, s32);
extern "C" void func_002366D8(H *, void *);
extern "C" f32 func_00239018(void *);
extern "C" void func_00239020(void *, f32);
extern "C" void func_002FC870(H *, s32);
extern "C" void func_002FE278(H *, s32);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

extern "C" void MScaleBar__get_index(H *self, void *a1, s32 mode, Obj **args) {
    H h;
    if (mode == 0) {
        func_002366D8(&h, a1);
        f32 f = func_00239018(h.p);
        func_00236680(&h, 2);
        /* The destination pointer is assigned in both arms: a two-set pseudo
           that takes $a0, so each arm loads it and reorg moves one copy into
           the branch delay slot (retail has it there, and a nop after the jal). */
        H *out;
        f32 r;
        if (f >= 0.0f) {
            out = &h;
            r = f + 0.5f;
        } else {
            out = &h;
            r = f - 0.5f;
        }
        func_002FE278(out, (s32)r);
        if (self != &h) {
            void *n = h.p;
            if (n != 0) func_003285A8(n);
            if (self->p != 0) func_003285F8(self->p);
            self->p = n;
        }
        func_002FC870(&h, 2);
    } else if (mode == 1) {
        func_002366D8(&h, a1);
        void *bar = h.p;
        Obj *o = *args;
        VEntry *e = (VEntry *)(o->vtbl + 0x60);
        func_00239020(bar, e->fn((char *)o + e->delta));
        func_00236680(&h, 2);
    }
}
