#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00430360(void *);                      /* extern */
s32 func_0043A3F8();                            /* extern */

extern char D_006879E0[];
struct func_00430320_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_00430320(struct func_00430320_arg0 *arg0) {
    func_0043A3F8();
    arg0->unk8 = 0x20;
    arg0->unk0 = (s32)D_006879E0;
    func_00430360(arg0);
}
