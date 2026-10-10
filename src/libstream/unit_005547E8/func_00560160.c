#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0055F4B0();                            /* extern */

extern char D_00689C08[];
struct func_00560160_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_00560160(struct func_00560160_arg0 *arg0) {
    func_0055F4B0();
    arg0->unk8 = 0;
    arg0->unk4 = 0;
    arg0->unk0 = (s32)D_00689C08;
}
