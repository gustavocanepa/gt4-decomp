#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RacePS2Base__virtual_147(s32, void *);
s32 func_004096F8(s32);
struct RaceLicense__virtual_147_arg1 {
    char pad0[0x18];
    void *unk18;
};
struct RaceLicense__virtual_147_temp_s2 {
    char pad0[0x545];
    u8 unk545;
};

s32 RaceLicense__virtual_147(s32 arg0, struct RaceLicense__virtual_147_arg1 *arg1) {
    struct RaceLicense__virtual_147_temp_s2 *temp_s2;
    temp_s2 = arg1->unk18;
    if ((func_004096F8(arg0 + 0x24E5C) != 0) && (temp_s2->unk545 != 0)) {
        return 0;
    }
    return RacePS2Base__virtual_147(arg0, arg1);
}
