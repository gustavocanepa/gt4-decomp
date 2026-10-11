#include "types.h"
#include "gt4/mToolTipFace.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00249FB8(void *);                      /* extern */
s32 mTextFace__virtual_67();                            /* extern */

struct mToolTipFace__virtual_67_arg1_unk10 {
    char pad0[0xA6];
    s16 unkA6;
};
struct mToolTipFace__virtual_67_arg1 {
    char pad0[0x10];
    struct mToolTipFace__virtual_67_arg1_unk10 *unk10;
};

void mToolTipFace__virtual_67(struct mToolTipFace *arg0, struct mToolTipFace__virtual_67_arg1 *arg1) {
    mTextFace__virtual_67();
    func_00249FB8(arg0);
    arg0->unk110 = (s32) (arg1->unk10->unkA6 < 4);
}
