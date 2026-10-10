#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578480(s32);                         /* extern */

struct func_00557E00_arg0 {
    char pad0[0x770];
    s32 unk770;
    char pad774[0x14];
    s32 unk788;
};

s32 func_00557E00(struct func_00557E00_arg0 *arg0) {
    if (arg0->unk770 == 0) {
        arg0->unk770 = 1;
        func_00578480(arg0->unk788);
    }
}
