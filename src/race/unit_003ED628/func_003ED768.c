#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { s32 id; s32 a; s32 b; } E;
void func_003ED768(E *arg0, s32 arg1) {
    s32 i;
    s32 func_00575DA0 = -1;
    for (i = 0; i < 6; i++) {
        if (arg0[i].id == 0) func_00575DA0 = i;
        if (arg0[i].id == arg1) return;
    }
    if (func_00575DA0 >= 0) { E *e = arg0 + func_00575DA0; e->id = arg1; }
}
