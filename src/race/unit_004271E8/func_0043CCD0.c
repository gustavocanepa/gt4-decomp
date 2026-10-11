#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00438A90();                            /* extern */
s32 func_0043BB00(s32);                         /* extern */
s32 func_0043C410(void *);                      /* extern */
s32 func_0043C6A8(void *);                      /* extern */
s32 func_0043C9B0(void *);                      /* extern */

extern char D_00687FF0[];
void func_0043CCD0(s32 *arg0) {
    func_00438A90();
    *arg0 = (s32)D_00687FF0;
    func_0043BB00(arg0 + 0x6);
    func_0043C410(arg0 + 0x12);
    func_0043C6A8(arg0 + 0x19);
    func_0043C9B0(arg0 + 0x23);
}
