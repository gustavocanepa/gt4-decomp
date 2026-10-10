#include "types.h"
#include "gt4/RaceDisplay.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s16 d; s16 pad; s32 (*fn)(void *); } E;
void RaceDisplay__virtual_12(struct RaceDisplay *arg0, s8 *arg1) {
    s32 temp_v0;
    s32 var_v1;
    E *e = (E *)(*(s8 **)arg1 + 0x108);
    temp_v0 = e->fn(arg1 + e->d);
    if (temp_v0 < 0 || (var_v1 = 0, !(temp_v0 < 2))) var_v1 = 1;
    if (arg0->unk24 != var_v1) {
        arg0->unk24 = var_v1;
        arg0->unk30 = (s32) ((arg0->unk30 & 0xFFFF00FF) | 0x100);
    }
}
