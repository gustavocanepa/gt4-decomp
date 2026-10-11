#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_003557E8_arg0 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
    s16 unk4;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
};

void AutomobileControl__clearPacket(char *arg0) {
    ((struct func_003557E8_arg0 *)arg0)->unk0 = 0;
    ((struct func_003557E8_arg0 *)arg0)->unk1 = 0;
    ((struct func_003557E8_arg0 *)arg0)->unk2 = 0;
    ((struct func_003557E8_arg0 *)arg0)->unk3 = 0;
    ((struct func_003557E8_arg0 *)arg0)->unk4 = 0;
    ((struct func_003557E8_arg0 *)arg0)->unk6 = 0;
    ((struct func_003557E8_arg0 *)arg0)->unk7 = 0;
    ((struct func_003557E8_arg0 *)arg0)->unk8 = 0;
    ((struct func_003557E8_arg0 *)arg0)->unkA = 0;
    ((struct func_003557E8_arg0 *)arg0)->unkC = 0;
    ((struct func_003557E8_arg0 *)arg0)->unkE = 0;
    func_005A48D8(arg0 + 0x10, 0, 0x10);
}

}
