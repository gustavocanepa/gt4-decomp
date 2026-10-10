#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00345BE0(void *);                      /* extern */
s32 func_0057ACD8();                            /* extern */

extern char D_00679970[];
struct func_00345AE8_arg0 {
    char pad0[0x48];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
};

void func_00345AE8(struct func_00345AE8_arg0 *arg0) {
    arg0->unk50 = (s32)D_00679970;
    func_0057ACD8();
    arg0->unk48 = 0;
    arg0->unk4C = 0;
    func_00345BE0(arg0);
}
