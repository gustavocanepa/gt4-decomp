#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055F4B0();                            /* extern */

extern char D_00689C08[];
struct func_00560198_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

s32 func_00560198(struct func_00560198_arg0 *arg0, s32 arg1, s32 arg2) {
    func_0055F4B0();
    arg0->unk8 = arg2;
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)D_00689C08;
}
