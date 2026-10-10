#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0043A3F8();                            /* extern */
s32 func_0043B5D8(void *);                      /* extern */

extern char D_00687F50[];
struct func_0043B598_arg0 {
    s32 unk0;
    char pad4[0x20];
    s32 unk24;
};

void func_0043B598(struct func_0043B598_arg0 *arg0) {
    func_0043A3F8();
    arg0->unk0 = (s32)D_00687F50;
    func_0043B5D8(arg0);
    arg0->unk24 = 0;
}
