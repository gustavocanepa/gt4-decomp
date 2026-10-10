#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_003951D0(void *);                      /* extern */
s32 func_003967F8(s32);                         /* extern */
s32 func_003D59F8(void *);                      /* extern */
s32 func_00463908(s32, s32);                /* extern */

extern char RaceCourse__model_arena_[];
struct func_00394E70_arg0 {
    s32 unk0;
    s32 unk4;
};

void RaceCourse__clearData(char *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = ((struct func_00394E70_arg0 *)arg0)->unk4;
    if (temp_v0 != 0) {
        func_003967F8(temp_v0);
    }
    temp_v0_2 = ((struct func_00394E70_arg0 *)arg0)->unk0;
    if (temp_v0_2 != 0) {
        func_00463908((s32)RaceCourse__model_arena_, temp_v0_2);
    }
    ((struct func_00394E70_arg0 *)arg0)->unk4 = 0;
    ((struct func_00394E70_arg0 *)arg0)->unk0 = 0;
    func_003D59F8(arg0 + 0x1C);
    func_003951D0(arg0);
}

}
