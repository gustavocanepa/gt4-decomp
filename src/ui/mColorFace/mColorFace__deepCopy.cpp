#include "types.h"

extern "C" void mWidget__deepCopy(void *arg0, void *arg1);
extern "C" void *__dynamic_cast_2(void *arg0, void *arg1, s32 arg2, void *arg3, void *arg4, void *arg5);
extern "C" void *func_005E49B0(void *arg0, void *arg1);
extern char mColorFace__tf[];
extern char hObject__tf[];

struct Bits { s32 value : 32; };

struct Ent285FC0 {
    s16 delta;
    s16 index;
    char *ptr;
};

static inline void copyFields(char *dst, char *src) {
    *(f32 *)(dst + 0xB0) = *(f32 *)(src + 0xB0);
    ((Bits *)(dst + 0xB4))->value = ((Bits *)(src + 0xB4))->value;
}

extern "C" void mColorFace__deepCopy(char *arg0, char *arg1) {
    char *r;
    Ent285FC0 *e;

    mWidget__deepCopy(arg0, arg1);
    r = 0;
    if (arg1 != 0) {
        e = *(Ent285FC0 **)(arg1 + 4);
        r = (char *)__dynamic_cast_2(e->ptr, mColorFace__tf, 0, arg1 + e->delta, hObject__tf, arg1);
    }
    if (r != 0) {
        if (arg0 + 0xA0 != r + 0xA0) {
            func_005E49B0(arg0 + 0xA0, r + 0xA0);
        }
        copyFields(arg0, r);
    }
}
