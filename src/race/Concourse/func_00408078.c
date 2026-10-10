#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005C1648(s32);                         /* extern */

struct func_00408078_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_00408078(struct func_00408078_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkC;
    if (temp_v0 != 0) {
        func_005C1648(temp_v0);
        arg0->unkC = 0;
    }
}
