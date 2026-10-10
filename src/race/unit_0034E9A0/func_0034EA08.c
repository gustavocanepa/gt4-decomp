#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern u8 D_00620E14;
struct func_0034EA08_p {
    char pad0[0xD0];
    f32 unkD0;
};

f32 func_0034EA08(s16 *p, f32 x) {
    if (D_00620E14 != 0) {
        f32 a = ((f32 *)(p + 4))[*p];
        a = a * a;
        return ((struct func_0034EA08_p *)p)->unkD0 * (x * x + a * 0x1.C71C70p-4f) / a;
    }
    return ((struct func_0034EA08_p *)p)->unkD0 * x;

}
