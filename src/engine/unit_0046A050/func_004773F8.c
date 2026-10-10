#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00476768(void *, s32 *);               /* extern */
s32 func_004768C0(void *);                      /* extern */
s32 func_004772A8(void *);                          /* extern */
s32 func_00478A18(s32 *);                           /* extern */
s32 func_0057D9C0(s32, s32, s32, s32);      /* extern */

void func_004773F8(s32 *arg0) {
    s8 sp[0x10];
    s32 temp_s1;

    func_00476768(sp, arg0);
    temp_s1 = func_00478A18(arg0);
    func_0057D9C0((s32)"type : %s(%d)  val : %s\012", temp_s1, *arg0, func_004772A8(sp));
    func_004768C0(sp);
}
