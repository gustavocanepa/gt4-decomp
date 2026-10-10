#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 mListBox__setDragIcon();                            /* extern */

struct func_002B5238_arg0 {
    char pad0[0x124];
    s32 unk124;
    char pad128[0x4];
    s32 unk12C;
    char pad130[0x1C];
    s32 unk14C;
};

void func_002B5238(struct func_002B5238_arg0 *arg0) {
    mListBox__setDragIcon();
    arg0->unk14C = 2;
    arg0->unk12C = (s32) arg0->unk124;
}
