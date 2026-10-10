#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004EFF40(void *);                      /* extern */
s32 func_004F0320(void *);                      /* extern */
s32 func_004F08B8(void *);                      /* extern */
s32 func_004F0908(void *);                      /* extern */
s32 func_004FFD40(void *);                      /* extern */
s32 func_00503560();                            /* extern */

struct func_004F0848_arg0 {
    char pad0[0x3C];
    s32 unk3C;
    char pad40[0x114];
    s32 unk154;
    char pad158[0xC];
    s32 unk164;
};

void func_004F0848(void *arg0) {
    if (((struct func_004F0848_arg0 *)arg0)->unk3C != 0) {
        ((struct func_004F0848_arg0 *)arg0)->unk164 = 1;
        func_00503560();
        func_004FFD40(arg0);
        if (((struct func_004F0848_arg0 *)arg0)->unk154 == 0) {
            func_004F0908(arg0);
        }
        func_004F08B8(arg0);
        func_004EFF40(arg0 + 0x40);
        func_004F0320(arg0);
        ((struct func_004F0848_arg0 *)arg0)->unk3C = 0;
    }
}
