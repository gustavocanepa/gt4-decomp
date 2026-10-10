#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00572048(void *);                      /* extern */
s32 func_00572470(void *);                      /* extern */

extern char D_00689D28[];
struct func_005720B8_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

void func_005720B8(void *arg0) {
    ((struct func_005720B8_arg0 *)arg0)->unk7C = (s32)D_00689D28;
    func_00572048(arg0 + 0x4C);
    func_00572470(arg0);
}
