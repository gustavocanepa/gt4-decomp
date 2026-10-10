/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00372170(s32);                         /* extern */
s32 func_00372190(s32);                         /* extern */
s32 func_003721B0(s32, s32, s32);       /* extern */
s32 CameraSys__CameraManager__setTargetCar(s32, s32);                    /* extern */
s32 func_003D8B78();                                /* extern */

struct func_003D9390_arg0 {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
    char pad6C[0x28];
    s32 unk94;
    s32 unk98;
};

void func_003D9390(struct func_003D9390_arg0 *arg0, s32 arg1) {
    s32 temp_a0;

    if (func_003D8B78() != 0) {
        if (arg0->unk68 != 0) {
            CameraSys__CameraManager__setTargetCar(arg1, arg0->unk64);
        }
        if (arg0->unk98 != 0) {
            temp_a0 = arg0->unk94;
            switch (temp_a0) {                      /* irregular */
            case 0:
                func_00372170(arg1);
                func_003721B0(arg1, 0, 0);
                break;
            case 1:
                func_00372170(arg1);
                func_003721B0(arg1, 0, 1);
                break;
            case 2:
                func_00372190(arg1);
                break;
            }
        }
    }
}
