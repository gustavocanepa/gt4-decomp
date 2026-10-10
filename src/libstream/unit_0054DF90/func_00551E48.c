#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055F4C0(s32 *, s32);              /* extern */
s32 func_00574DA8(void *, s32);             /* extern */
s32 func_0057CB80(s32, void *);                 /* extern */
s32 func_005C1628(s32 *);                       /* extern */

extern char D_006898A8[];
extern char D_0064C878[];
void func_00551E48(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_006898A8;
    func_0057CB80(*(s32 *)D_0064C878, arg0 + 1);
    func_00574DA8(arg0 + 4, 2);
    func_0055F4C0(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
