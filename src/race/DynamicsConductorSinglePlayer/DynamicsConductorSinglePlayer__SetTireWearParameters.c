#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 SetHardCodedTireWearParameters(s32, s32);                        /* extern */
s32 RaceOrganization__validArcadeOption(void *);                          /* extern */

struct DynamicsConductorSinglePlayer__virtual_10_temp_s1 {
    char pad0[0x8];
    s32 unk8;
};

s32 DynamicsConductorSinglePlayer__SetTireWearParameters(void **arg0, s32 arg1) {
    struct DynamicsConductorSinglePlayer__virtual_10_temp_s1 *temp_s1;

    temp_s1 = *arg0;
    if (RaceOrganization__validArcadeOption(temp_s1) != 0) {
        return SetHardCodedTireWearParameters(arg1, temp_s1->unk8);
    }
    return 1;
}
