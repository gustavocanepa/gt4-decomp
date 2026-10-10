#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00386660(void *, s32);                 /* extern */
s32 func_00386698(void *, s32, s32, s32, s32);  /* extern */
s32 func_00446178(s32, s32 *, s32 *, s32 *, s32 *); /* extern */

void func_00385410(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;

    func_00386660(sp, arg1 + 0x6E0);
    func_00446178(arg0, &sp10, &sp14, &sp18, &sp1C);
    func_00386698(sp, sp10, sp14, sp18, sp1C);
}
