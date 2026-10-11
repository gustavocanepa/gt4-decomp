#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005220D8(void *);                      /* extern */
s32 func_005220F8();                                /* extern */
s32 func_00522AA0(s32);                         /* extern */

struct func_00520E60_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_00520E60(struct func_00520E60_arg0 *arg0) {
    if (func_005220F8() == 0) {
        return;
    }
    func_00522AA0(arg0->unk8);
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    func_005220D8(arg0);
}
