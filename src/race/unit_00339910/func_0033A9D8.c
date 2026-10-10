#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045B0F8(void *);                      /* extern */
s32 func_0045B228(void *);                      /* extern */
s32 func_0045B620(void *, void *);              /* extern */
s32 func_0045B768(void *, void *, s32);     /* extern */

extern char D_0069F310[];
struct func_0033A9D8_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_0033A9D8(struct func_0033A9D8_arg0 *arg0) {
    s32 frag1;
    s8 sp[0x10];
    s32 temp_s1;

    frag1 = arg0->unk0;
    temp_s1 = arg0->unk8 - frag1;
    func_0045B768(sp, arg0, (s32)D_0069F310);
    func_0045B620(sp, arg0);
    func_0045B0F8(arg0);
    func_0045B228(arg0);
    func_0045B228(arg0);
    func_0045B0F8(arg0);
    arg0->unk8 = (s32) (arg0->unk0 + temp_s1);
}
