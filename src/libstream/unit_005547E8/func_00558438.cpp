#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_00578480(...);
s32 func_00557E68(...);
s32 func_00557E38(void *);                      /* extern */

struct func_00558438_arg0 {
    char pad0[0x76C];
    s32 unk76C;
    s32 unk770;
    char pad774[0x4];
    s32 unk778;
    char pad77C[0xC];
    s32 unk788;
};

void func_00558438(char *arg0) {
    ((struct func_00558438_arg0 *)arg0)->unk76C = 0;
    if (((struct func_00558438_arg0 *)arg0)->unk778 != 0) {
        func_00557E68(arg0, 0);
    }
    if (((struct func_00558438_arg0 *)arg0)->unk770 != 0) {
        func_00557E38(arg0);
    }
    func_00578480(((struct func_00558438_arg0 *)arg0)->unk788);
}

}
