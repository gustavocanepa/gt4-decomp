#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001C5178(void *);                      /* extern */
s32 func_001C5320(void *);                      /* extern */
s32 func_00576788(s32);                     /* extern */
s32 func_005767C0(s32);                     /* extern */

extern char D_008286F0[];
struct func_001C4D20_arg0 {
    char pad0[0x274];
    s32 unk274;
    s32 unk278;
    char pad27C[0x10];
    s32 unk28C;
};

void func_001C4D20(void *arg0) {
    func_00576788((s32)D_008286F0);
    if (((struct func_001C4D20_arg0 *)arg0)->unk274 == 0) {
        ((struct func_001C4D20_arg0 *)arg0)->unk28C = 0;
        ((struct func_001C4D20_arg0 *)arg0)->unk274 = 1;
        func_001C5178(arg0);
        if (((struct func_001C4D20_arg0 *)arg0)->unk278 != 0) {
            func_001C5320(arg0);
        }
    }
    func_005767C0((s32)D_008286F0);
}
