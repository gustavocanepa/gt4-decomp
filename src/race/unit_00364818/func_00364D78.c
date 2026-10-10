#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 p0; u8 n; u8 pad[0x12]; u8 b[1]; } V;
V *func_00359510(s32);
typedef struct { u8 pad[0x8D4]; f32 f[1]; } T;
f32 func_00364D78(T **arg0, s32 arg1) {
    T *temp_s1;
    u8 var_a0;
    V *temp_v0;
    temp_s1 = *arg0;
    temp_v0 = func_00359510((s32)temp_s1 + 0x600);
    var_a0 = 0;
    if (arg1 < temp_v0->n) {
        var_a0 = temp_v0->b[arg1];
    }
    return temp_s1->f[var_a0];
}
