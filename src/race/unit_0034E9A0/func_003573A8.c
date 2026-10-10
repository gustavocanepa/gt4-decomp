#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { u8 p0; u8 n; u8 pad[0x12]; u8 b[1]; } V;
typedef struct { u8 pad[0x2D4]; f32 f[1]; } T;
V *func_00359510(T *);
f32 func_003573A8(T *arg0, s32 arg1, f32 fparg0) {
    u8 var_v0;
    V *temp_v0;
    temp_v0 = func_00359510(arg0);
    var_v0 = 0;
    if (arg1 < temp_v0->n) {
        var_v0 = temp_v0->b[arg1];
    }
    return fparg0 / arg0->f[var_v0];
}
