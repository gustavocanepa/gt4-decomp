#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00688628[];
struct func_00453680_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_00453680(struct func_00453680_arg0 *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)D_00688628;
}
