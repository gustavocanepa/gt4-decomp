#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s32 flags; u8 pad2[0x40]; } E;
typedef struct { u8 pad[0x28]; E e[8]; } T;
struct func_0045C530_arg0 {
    char pad0[0x430];
    s32 unk430;
};

void func_0045C530(T *arg0, s32 arg1) {
    s32 i;
    if ((((struct func_0045C530_arg0 *)arg0)->unk430 != 0) && (arg1 == 0)) {
        for (i = 0; i < 8; i++) {
            arg0->e[i].flags &= ~2;
        }
    }
    ((struct func_0045C530_arg0 *)arg0)->unk430 = arg1;
}
