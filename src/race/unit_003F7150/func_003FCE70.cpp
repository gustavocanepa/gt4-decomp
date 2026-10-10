#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_003FCE70_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_003FCE70(char *arg0) {
    ((struct func_003FCE70_arg0 *)arg0)->unk0 = 7;
    ((struct func_003FCE70_arg0 *)arg0)->unk4 = 0;
    func_005A48D8(arg0 + 8, 0, 0xC);
}

}
