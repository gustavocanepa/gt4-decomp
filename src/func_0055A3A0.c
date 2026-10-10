#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0055C588(s32);                         /* extern */

extern char SDDRV__VoiceSystem__master_[];
struct func_0055A3A0_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

void func_0055A3A0(struct func_0055A3A0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = func_0055C588((s32)SDDRV__VoiceSystem__master_);
    arg0->unk18 = temp_v0;
    arg0->unk14 = 1;
}
