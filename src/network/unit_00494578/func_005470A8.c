#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_006C5320[];
void func_005470A8(s32 *arg0) {
    if (((u16) *(u16 *)D_006C5320 >> 8) == 0x23) {
        *arg0 = 1;
        return;
    }
    *arg0 = 0;
}
