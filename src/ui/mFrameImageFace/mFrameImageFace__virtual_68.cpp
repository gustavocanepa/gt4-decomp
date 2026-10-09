typedef int s32;

struct Handle {
    s32 p;
};

struct Obj {
    char pad0[0x110];
    Handle h[8];
};

extern "C" void mImageFace__virtual_68(void);
extern "C" void func_002106E0(Handle *, s32 *);
extern "C" void func_00210710(Handle *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

static inline void assign(Handle *dst, Handle *src) {
    if (dst != src) {
        s32 v = src->p;
        if (v != 0) {
            func_003285A8(v);
        }
        if (dst->p != 0) {
            func_003285F8(dst->p);
        }
        dst->p = v;
    }
}

#define SET(i, z)                       \
    {                                   \
        Handle *d = &self->h[i];        \
        z = 0;                          \
        func_002106E0(&tmp[0], &z);        \
        assign(d, &tmp[0]);                \
        func_00210710(&tmp[0], 2);         \
    }

extern "C" void mFrameImageFace__virtual_68(Obj *self) {
    Handle tmp[4];
    s32 z0, z1, z2, z3, z4, z5, z6, z7;

    mImageFace__virtual_68();
    SET(0, z0)
    SET(1, z1)
    SET(2, z2)
    SET(3, z3)
    SET(4, z4)
    SET(5, z5)
    SET(6, z6)
    SET(7, z7)
}
