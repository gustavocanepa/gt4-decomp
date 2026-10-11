#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RacePS2Base__is_able_to_render_this_car(s32, void *);
s32 LicenseConcourse__isCameraPeriod(s32);
struct RaceLicense__virtual_147_arg1 {
    char pad0[0x18];
    void *unk18;
};
struct RaceLicense__virtual_147_temp_s2 {
    char pad0[0x545];
    u8 unk545;
};

s32 RaceLicense__is_able_to_render_this_car(s32 arg0, struct RaceLicense__virtual_147_arg1 *arg1) {
    struct RaceLicense__virtual_147_temp_s2 *temp_s2;
    temp_s2 = arg1->unk18;
    if ((LicenseConcourse__isCameraPeriod(arg0 + 0x24E5C) != 0) && (temp_s2->unk545 != 0)) {
        return 0;
    }
    return RacePS2Base__is_able_to_render_this_car(arg0, arg1);
}
