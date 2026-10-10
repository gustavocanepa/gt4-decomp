#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char RaceLapTime__vtable[];
typedef struct { s32 a[5]; s32 t[1000]; s32 vt; } T;
void RaceLapTime__structor_0(T *arg0) {
    s32 i;
    s32 k;
    arg0->a[0] = 0;
    arg0->a[1] = 0;
    k = 0x157529FF;
    arg0->a[2] = 0;
    arg0->a[3] = 0;
    arg0->a[4] = 0;
    arg0->vt = (s32)RaceLapTime__vtable;
    for (i = 999; i >= 0; i--) {
        arg0->t[i] = k;
    }
}
