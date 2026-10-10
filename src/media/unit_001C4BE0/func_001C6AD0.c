#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001C6B78(void *);                      /* extern */
s32 func_001C7698(void *);                      /* extern */

extern char D_00660CC0[];
struct func_001C6AD0_arg0 {
    char pad0[0x1DD8];
    s32 unk1DD8;
    s32 unk1DDC;
};

void func_001C6AD0(void *arg0) {
    ((struct func_001C6AD0_arg0 *)arg0)->unk1DDC = (s32)D_00660CC0;
    func_001C7698(arg0 + 0xBD8);
    func_001C6B78(arg0);
    ((struct func_001C6AD0_arg0 *)arg0)->unk1DD8 = 0;
}
