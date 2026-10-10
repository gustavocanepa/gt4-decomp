#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 CourseData__getRunway(void *);                          /* extern */
s32 func_00397438();                            /* extern */
s32 func_00457EF8(s32, s32);                    /* extern */

struct func_00396A48_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

void func_00396A48(void *arg0) {
    func_00397438();
    if (((struct func_00396A48_arg0 *)arg0)->unk8C != 0) {
        func_00457EF8(((struct func_00396A48_arg0 *)arg0)->unk8C, CourseData__getRunway(arg0));
    }
}
