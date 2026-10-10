#include "types.h"
#include "gt4/ShowRoomCar.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char ShowRoomCar__vtable[];
void ShowRoomCar__structor_1(struct ShowRoomCar *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk8 = (s32)ShowRoomCar__vtable;
    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        func_00575DA0(temp_v1);
    }
    arg0->unk4 = 0;
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
