#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005656E8(s32, void *);                 /* extern */

extern char D_00654E20[];
struct func_00565698_arg0 {
    char pad0[0x58];
    s32 unk58;
};

s32 func_00565698(struct func_00565698_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = (arg0->unk58 * 0x68) + (s32)D_00654E20;
    func_005656E8(temp_s0, arg0);
    return temp_s0;
}
