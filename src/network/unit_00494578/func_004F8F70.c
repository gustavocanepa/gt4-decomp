/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004F8E20(s32, s32, s32, s32, s32); /* extern */
s32 func_004F9230();                            /* extern */

struct func_004F8F70_arg1 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_004F8F70(s32 arg0, struct func_004F8F70_arg1 *arg1) {
    func_004F9230();
    func_004F8E20(arg0, arg1->unk0, arg1->unk8, 0, 0);
}
