#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 ShowRoomCar__structor_0(void *);                      /* extern */
s32 ShowRoomCar__structor_1(void *, s32);             /* extern */
s32 func_00364868(void *, s32, s32);        /* extern */
f32 func_00364F00(void *);                          /* extern */

struct func_00110A18_arg0_unk60 {
    char pad0[0x8];
    s32 *unk8;
};
struct func_00110A18_arg0 {
    char pad0[0x60];
    struct func_00110A18_arg0_unk60 *unk60;
};

f32 func_00110A18(struct func_00110A18_arg0 *arg0) {
    s8 sp[0x10];
    f32 temp_f20;

    ShowRoomCar__structor_0(sp);
    func_00364868(sp, *arg0->unk60->unk8 + 0x20, 0);
    temp_f20 = func_00364F00(sp);
    ShowRoomCar__structor_1(sp, 2);
    return temp_f20;
}
