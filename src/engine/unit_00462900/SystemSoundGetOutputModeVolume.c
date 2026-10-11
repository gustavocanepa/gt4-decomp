#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 pad[0x10]; s32 w; f32 v[1]; } T;
extern T *D_00623A48;
f32 SystemSoundGetOutputModeVolume(s32 i, s32 j) {
    T *t;
    if (!(i < 3 && j < 4)) return 1.0f;
    t = D_00623A48;
    if (t != 0) return t->v[t->w * i + j];
    return 1.0f;

}
