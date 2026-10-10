#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0064A1F4[];
extern char D_0064A2C0[];
extern char D_0064A2CC[];
s32 func_00507070(s32 arg0, s32 arg1) {
    *(s32 *)D_0064A2CC = arg0;
    *(s32 *)D_0064A2C0 = arg1;
    *(s32 *)D_0064A1F4 = 3;
    return 0;
}
