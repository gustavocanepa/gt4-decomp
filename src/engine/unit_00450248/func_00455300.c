#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 ModelSet2__begin(s32, s32 *);                  /* extern */
s32 ModelSet2___render(s32, s32, s32 *);                 /* extern */
s32 func_0049CE40(s32);                         /* extern */

struct func_00455300_arg0 {
    char pad0[0x40];
    s32 unk40;
};

s32 func_00455300(struct func_00455300_arg0 *arg0, s32 arg1, s32 *arg2) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = *arg2;
    ModelSet2__begin(temp_s1, arg2);
    temp_s0 = ModelSet2___render(temp_s1, arg1, arg2);
    func_0049CE40(arg0->unk40);
    return temp_s0;
}
