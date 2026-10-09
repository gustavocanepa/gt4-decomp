typedef int s32;
typedef float f32;

struct Dst {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct Src {
    char pad0[4];
};

struct VObj {
    char pad0[4];
    union {
        char *vtbl;
        s32 word;
    } u;
};

struct VEntryVal {
    short delta;
    short index;
    f32 (*fn)(void *);
};

extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" struct Dst *func_00268228(struct Dst *arg0, struct Src *arg1);
extern "C" void func_00268308(struct Src *arg0, struct Dst *arg1);
extern "C" void func_002ED5C0(void *arg0, int arg1);
extern "C" void func_002ED618(void *arg0, void *arg1);
extern "C" void func_002EFC48(void *arg0, s32 arg1);
extern "C" s32 *func_002EFCE0(void *arg0, s32 arg1);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, float fparg0);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

#define ASSIGN(dst, src)     if ((dst) != (src)) {         newVal = (src)[0];         if (newVal != 0) {             func_003285A8(newVal);         }         oldVal = *(dst);         if (oldVal != 0) {             func_003285F8(oldVal);         }         *(dst) = newVal;     }

static inline void init4(struct Dst *v, f32 x, f32 y, f32 z, f32 w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

static inline f32 vcall(struct VObj *q) {
    struct VEntryVal *e2 = (struct VEntryVal *)(q->u.vtbl + 0x60);
    return e2->fn((char *)q + e2->delta);
}

extern "C" void func_00256250(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    struct Src *h[4];
    union {
        struct Dst v;
        s32 arr1[4];
    } u;
    func_00255110(h, arg1);
    if (arg2 == 0) {
        s32 arr[4];
        s32 buf[4];
        s32 *buf0;
        s32 *arr0;
        s32 *e;
        s32 newVal;
        s32 oldVal;
        func_00268228(&u.v, h[0]);
        arr0 = arr;
        func_002EFC48(arr0, 4);
        e = func_002EFCE0(arr0, 0);
        buf0 = buf;
        func_002F9360(buf0, u.v.x);
        ASSIGN(e, buf0);
        func_002F7B68(buf0, 2);
        e = func_002EFCE0(arr0, 1);
        func_002F9360(buf0, u.v.y);
        ASSIGN(e, buf0);
        func_002F7B68(buf0, 2);
        e = func_002EFCE0(arr0, 2);
        func_002F9360(buf0, u.v.z);
        ASSIGN(e, buf0);
        func_002F7B68(buf0, 2);
        e = func_002EFCE0(arr0, 3);
        func_002F9360(buf0, u.v.w);
        ASSIGN(e, buf0);
        func_002F7B68(buf0, 2);
        ASSIGN(arg0, arr0);
        func_002ED5C0(arr0, 2);
    } else if (arg2 == 1) {
        struct Dst vec;
        struct Dst *pvec;
        s32 *arr0;
        arr0 = u.arr1;
        func_002ED618(arr0, arg3);
        pvec = &vec;
        init4(pvec, 0.0f, 0.0f, 0.0f, 0.0f);
        vec.x = vcall(*(struct VObj **)func_002EFCE0(arr0, 0));
        vec.y = vcall(*(struct VObj **)func_002EFCE0(arr0, 1));
        vec.z = vcall(*(struct VObj **)func_002EFCE0(arr0, 2));
        vec.w = vcall(*(struct VObj **)func_002EFCE0(arr0, 3));
        func_00268308(h[0], pvec);
        func_002ED5C0(arr0, 2);
    }
    func_002550B8(h, 2);
}
