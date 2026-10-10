#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_006889A8[];
struct func_00471FD8_arg0 {
    s32 unk0;
    char pad4[0x100];
    s32 unk104;
};

s32 func_00471FD8(struct func_00471FD8_arg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk104 = (s32)D_006889A8;
}
