typedef int s32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

union Vec {
    u128 q;
    f32 f[4];
};

struct Obj {
    s32 flag;
    s32 pad[3];
    Vec pos;
};

struct Src {
    char pad[0x50];
    Vec pos;
    char pad2[0x80];
    f32 offset;
};

extern "C" s32 EasyHandleSolver__solve(Obj *self, s32 arg1, s32 arg2, Src *src) {
    Vec *v = &self->pos;
    v->q = src->pos.q;
    f32 x = v->f[0];
    f32 r;
    if (self->flag == 0)
        r = x + src->offset;
    else
        r = x - src->offset;
    v->f[0] = r;
    return 1;
}
