#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 DynamicsConductor__structor_1(void *, s32);             /* extern */
s32 RaceLicenseBGM__structor_1(void *, s32);             /* extern */
s32 func_003BC6A0();                            /* extern */
s32 RaceLicenseDisplay__structor_1(void *, s32);             /* extern */
s32 RacePause__structor_1(void *, s32);             /* extern */
s32 ResultLicense__structor_1(void *, s32);             /* extern */
s32 RaceSolitaire__structor_1(void *, s32);             /* extern */
s32 LicenseConcourse__structor_1(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char RaceLicense__vtable[];
extern char DynamicsConductorLicense__vtable[];
struct DynamicsConductorLicense__structor_0_temp_v1 {
    char pad0[0x10140];
    s32 unk10140;
};

struct DynamicsConductorLicense__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void DynamicsConductorLicense__structor_0(void *arg0, s32 arg1) {
    struct DynamicsConductorLicense__structor_0_temp_v1 *temp_v1;

    ((struct DynamicsConductorLicense__structor_0_arg0 *)arg0)->unk64 = (s32)RaceLicense__vtable;
    func_003BC6A0();
    LicenseConcourse__structor_1(arg0 + 0x24E5C, 2);
    ResultLicense__structor_1(arg0 + 0x24838, 2);
    temp_v1 = arg0 + 0x146F0;
    temp_v1->unk10140 = (s32)DynamicsConductorLicense__vtable;
    DynamicsConductor__structor_1(temp_v1, 0);
    RaceLicenseDisplay__structor_1(arg0 + 0x10368, 2);
    RaceLicenseBGM__structor_1(arg0 + 0xF178, 2);
    RacePause__structor_1(arg0 + 0xF140, 2);
    RaceSolitaire__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
