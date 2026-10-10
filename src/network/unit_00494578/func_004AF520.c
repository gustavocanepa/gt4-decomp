#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00576788();                            /* extern */
s32 func_005767C0(void *);                      /* extern */

struct func_004AF520_arg0 {
    char pad0[0x98];
    s32 unk98;
};

s32 func_004AF520(struct func_004AF520_arg0 *arg0) {
    s32 temp_s1;

    func_00576788();
    temp_s1 = arg0->unk98;
    arg0->unk98 = 1;
    func_005767C0(arg0);
    return temp_s1 ^ 1;
}
