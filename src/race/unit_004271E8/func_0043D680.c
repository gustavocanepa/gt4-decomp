#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0043D680_arg0 {
    char pad0[0x8];
    s16 unk8;
    s8 unkA;
    s8 unkB;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    s8 unk13;
    s8 unk14;
};

void *func_0043D680(void *arg0) {
    ((struct func_0043D680_arg0 *)arg0)->unk8 = 0xE;
    ((struct func_0043D680_arg0 *)arg0)->unkD = 1;
    ((struct func_0043D680_arg0 *)arg0)->unkA = 0;
    ((struct func_0043D680_arg0 *)arg0)->unkB = 0;
    ((struct func_0043D680_arg0 *)arg0)->unkC = 0;
    ((struct func_0043D680_arg0 *)arg0)->unkE = 0;
    ((struct func_0043D680_arg0 *)arg0)->unkF = 0;
    ((struct func_0043D680_arg0 *)arg0)->unk10 = 0;
    ((struct func_0043D680_arg0 *)arg0)->unk11 = 0;
    ((struct func_0043D680_arg0 *)arg0)->unk12 = 0;
    ((struct func_0043D680_arg0 *)arg0)->unk13 = 0;
    ((struct func_0043D680_arg0 *)arg0)->unk14 = 0;
    return arg0 + 8;
}
