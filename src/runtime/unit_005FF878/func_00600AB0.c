#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A408(s32 *, s32);              /* extern */
s32 func_005C1628(s32 *);                       /* extern */
s32 func_00600A40(s32, s32);                /* extern */

extern char D_00687908[];
void func_00600AB0(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_00687908;
    func_00600A40(arg0 + 2, 2);
    func_0043A408(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
