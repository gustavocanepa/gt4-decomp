#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 ShowRoomCar__structor_0(void *);                      /* extern */
s32 ShowRoomCar__structor_1(void *, s32);             /* extern */
s32 func_00364868(void *, s32, s32);            /* extern */
f32 func_00364F00(void *);                          /* extern */
s32 func_00441248(s32);                             /* extern */

f32 func_00110A80(s32 arg0) {
    s8 sp[0x10];
    f32 temp_f20;

    ShowRoomCar__structor_0(sp);
    func_00364868(sp, func_00441248(arg0), arg0 + 0x4A0);
    temp_f20 = func_00364F00(sp);
    ShowRoomCar__structor_1(sp, 2);
    return temp_f20;
}
