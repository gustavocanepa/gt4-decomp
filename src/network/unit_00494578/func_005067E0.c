#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00506388();                            /* extern */
s32 func_00506840();                            /* extern */
s32 func_0050F080();                            /* extern */
s32 func_0050F780();                            /* extern */
s32 func_00538C68(s32);                     /* extern */
s32 func_005397D0(s32);                     /* extern */

extern char D_0064A2E8[];
extern char D_00853550[];
extern char D_0064A1F4[];
s32 func_005067E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_00506388();
    func_00506840();
    func_0050F080();
    func_0050F780();
    func_00538C68((s32)D_0064A2E8);
    func_005397D0((s32)D_00853550);
    *(s32 *)D_0064A1F4 = 5;
    return 0;
}
