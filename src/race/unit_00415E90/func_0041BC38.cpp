/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));

static inline float sqrtf_(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj {
    char pad0[0x30];
    Vec4 dir;
    float length;
    float invLength;
};

extern "C" void func_0041BC38(Obj *self, Vec4 *v)
{
    Vec4 *d = &self->dir;
    *(u128 *)d = *(u128 *)v;
    float len = sqrtf_(d->x * d->x + d->y * d->y + d->z * d->z);
    self->length = len;
    if (len == 0.0f)
        self->invLength = 0.0f;
    else
        self->invLength = 1.0f / len;
}
