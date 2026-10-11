#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct mWidget {
    s32 unk0;
    void * unk4;
    s32 unk8;
    void * unkC;
    s32 unk10;
    s32 unk14;
    char unk_18[0x10];
    s32 unk28;
    s32 unk2C;
    char unk_30[0x24];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char unk_60[0x4];
    void * unk64;
    char unk_68[0xC];
    f32 unk74;
    f32 unk78;
    char unk_7C[0xC];
    f32 unk88;
    void * unk8C;
    void * unk90;
    void * unk94;
    s32 unk98;
    s32 unk9C;
    char unk_A0[0x4];
    s32 unkA4;
};
struct mComposite {
    s32 unk0;
    void * unk4;
    s32 unk8;
    void * unkC;
    s32 unk10;
    s32 unk14;
    char unk_18[0x10];
    s32 unk28;
    s32 unk2C;
    char unk_30[0x24];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char unk_60[0x4];
    void * unk64;
    char unk_68[0xC];
    f32 unk74;
    f32 unk78;
    char unk_7C[0xC];
    f32 unk88;
    void * unk8C;
    void * unk90;
    void * unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
};
int func_00206868(struct mWidget *);
s32 func_0025C300(void *);
s32 func_00207378(struct mComposite *, s32, void *); /* extern */
s32 func_00263C40(void *);                      /* extern */

void mComposite__doRenderChildren(struct mComposite *arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = func_00206868((struct mWidget *) arg0);
    if (var_s0 != 0) {
        do {
            func_00263C40((void *) var_s0);
            func_00207378(arg0, arg1, (void *) var_s0);
            var_s0 = func_0025C300((void *) var_s0);
        } while (var_s0 != 0);
    }
}
