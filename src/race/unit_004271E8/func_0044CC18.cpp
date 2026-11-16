#include "types.h"

struct Blk8 {
    s32 a;
    s32 b;
};

typedef void (*F2)(s32, s32);

extern "C" void *func_004AE1F8(s32, s32);
extern "C" void func_004AED20(void *, void *);
extern "C" void *__dynamic_cast_2(s32, s32, s32, s32, s32, s32);

extern char D_0060B030[];
extern char D_0060AD40[];
extern char D_008463B0[];

extern "C" void func_0044CC18(s32 arg0, Blk8 *arg1, Blk8 *arg2, s32 arg3) {
    char *v;
    char *r;
    char *t;
    F2 f;

    v = (char *)func_004AE1F8(0, arg0);
    if (v != 0) {
        t = *(char **)(v + 0xA8);
        r = (char *)__dynamic_cast_2(*(s32 *)(t + 4), (s32)D_0060B030, 0,
                                  (s32)(v + *(s16 *)t), (s32)D_0060AD40, (s32)v);
        *(Blk8 *)(r + 0xE0) = *arg1;
        *(s32 *)(r + 0xC0) = arg3;
        *(s32 *)(r + 0x60) = 1;
        *(s32 *)(r + 0x74) = 0;
        if (arg2->a != 0) {
            *(Blk8 *)(r + 0x6C) = *arg2;
        }
        return func_004AED20((void *)D_008463B0, r);
    } else {
        f = (F2)arg2->a;
        if (f != 0) {
            f(arg2->b, 0);
        }
    }
}
