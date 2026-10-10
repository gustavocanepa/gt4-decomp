typedef int s32;
typedef float f32;

struct Dst {
    f32 x;
    f32 y;
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
extern "C" struct Dst *func_00267CD0(struct Dst *arg0, struct Src *arg1);
extern "C" void mWidget__setScale(struct Src *arg0, struct Dst *arg1);
extern "C" void func_002ED5C0(void *arg0, int arg1);
extern "C" void func_002ED618(void *arg0, void *arg1);
extern "C" void func_002EFC48(void *arg0, s32 arg1);
extern "C" s32 *HArray__operator_index(void *arg0, s32 arg1);
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, float fparg0);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

static inline f32 getx(const struct Dst *v) { return v->x; }
static inline f32 gety(const struct Dst *v) { return v->y; }

#define ASSIGN(dst, src)     if ((dst) != (src)) {         newVal = (src)[0];         if (newVal != 0) {             func_003285A8(newVal);         }         oldVal = *(dst);         if (oldVal != 0) {             func_003285F8(oldVal);         }         *(dst) = newVal;     }

extern "C" void MWidget__get_scale(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
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
        func_00267CD0(&u.v, h[0]);
        arr0 = arr;
        func_002EFC48(arr0, 2);
        e = HArray__operator_index(arr0, 0);
        buf0 = buf;
        func_002F9360(buf0, getx(&u.v));
        ASSIGN(e, buf0);
        func_002F7B68(buf0, 2);
        e = HArray__operator_index(arr0, 1);
        func_002F9360(buf0, gety(&u.v));
        ASSIGN(e, buf0);
        func_002F7B68(buf0, 2);
        ASSIGN(arg0, arr0);
        func_002ED5C0(arr0, 2);
    } else if (arg2 == 1) {
        struct Dst vec;
        struct Dst *pvec;
        s32 *arr0;
        struct Src *o;
        f32 x;
        f32 y;
        arr0 = u.arr1;
        func_002ED618(arr0, arg3);
        pvec = &vec;
        o = h[0];
        {
            struct VObj *q = *(struct VObj **)HArray__operator_index(arr0, 0);
            struct VEntryVal *e2 = (struct VEntryVal *)(q->u.vtbl + 0x60);
            x = e2->fn((char *)q + e2->delta);
        }
        {
            struct VObj *q = *(struct VObj **)HArray__operator_index(arr0, 1);
            struct VEntryVal *e2 = (struct VEntryVal *)(q->u.vtbl + 0x60);
            y = e2->fn((char *)q + e2->delta);
        }
        pvec->x = x;
        pvec->y = y;
        mWidget__setScale(o, pvec);
        func_002ED5C0(arr0, 2);
    }
    func_002550B8(h, 2);
}
