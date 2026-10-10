#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00531878_arg1 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

s32 func_00531878(s32 arg0, struct func_00531878_arg1 *arg1) {
    if ((arg0 != 0) && (arg1 != NULL)) {
        func_0057DA20(arg0, (s32)"%u.%u.%u.%u", arg1->unk0, arg1->unk1, arg1->unk2, arg1->unk3);
        return 0;
    }
    return 0xA;
}
