#include "types.h"
#include "gt4/ShowRoomCar.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DC8(s32);
extern char ShowRoomCar__vtable[];
s32 ShowRoomCar__structor_0(struct ShowRoomCar *arg0) {
    s32 temp_v0;

    arg0->unk8 = (s32)ShowRoomCar__vtable;
    temp_v0 = func_00575DC8(0x1800);
    arg0->unk4 = 0;
    arg0->unk0 = temp_v0;
    return temp_v0;
}
