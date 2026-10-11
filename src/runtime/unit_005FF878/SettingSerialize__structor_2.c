#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char SettingSerialize__vtable[];
struct SettingSerialize {
    /* 0x00 */ void *unk0;
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s32 unk8;                        /* inferred */
    /* 0x08 */ char pad8[0x5C];
    /* 0x64 */ void *unk64;
    /* 0x68 */ char pad68[4];
    /* 0x6C */ s32 unk6C;
};                                                  /* size = 0x70 */

s32 func_00444190(s32 *);                   /* extern */

void SettingSerialize__structor_2(struct SettingSerialize *arg0) {
    func_0044CF80(arg0);
    arg0->unk0 = (void *)(s32)SettingSerialize__vtable;
    func_00444190(&arg0->unk8);
}
