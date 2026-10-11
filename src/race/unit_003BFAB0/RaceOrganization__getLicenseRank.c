#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 SPEC_DATABASE__RaceSpec__getBronzeTime(s32);
s32 SPEC_DATABASE__RaceSpec__getGoldTime(s32);
s32 SPEC_DATABASE__RaceSpec__getSilverTime(s32);
struct func_003C0B88_arg0 {
    char pad0[0x70];
    s32 unk70;
};

s32 RaceOrganization__getLicenseRank(struct func_003C0B88_arg0 *arg0, s32 arg1) {
    switch (arg1) {
    case 1:
        return SPEC_DATABASE__RaceSpec__getBronzeTime(arg0->unk70);
    case 2:
        return SPEC_DATABASE__RaceSpec__getGoldTime(arg0->unk70);
    case 3:
        return SPEC_DATABASE__RaceSpec__getSilverTime(arg0->unk70);
    }
    return 0;
}
