#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0033CF48();                                /* extern */
s32 func_0038BB50(void *, s32);                 /* extern */
s32 RaceLicenseBGM__structor_0(s32);                         /* extern */
s32 RaceLicenseDisplay__structor_0(s32);                         /* extern */
s32 ResultLicense__structor_0(void *);                      /* extern */
s32 func_003E1B28(void *, void *);              /* extern */
s32 RaceTrainingBase__structor_0();                            /* extern */
s32 DynamicsConductorLicense__structor_3(void *);                      /* extern */

extern char RaceTraining__vtable[];
extern char DynamicsConductorTraining__vtable[];
struct DynamicsConductorTraining__structor_0_temp_s0 {
    char pad0[0x10140];
    s32 unk10140;
};

struct DynamicsConductorTraining__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    void *unk70;
    s32 unk74;
    char pad78[0xCF0];
    s32 unkD68;
};

void DynamicsConductorTraining__structor_0(void *arg0) {
    s32 temp_s2;
    s32 temp_s4;
    struct DynamicsConductorTraining__structor_0_temp_s0 *temp_s0;
    void *temp_s1;

    temp_s4 = arg0 + 0x23F5C;
    RaceTrainingBase__structor_0();
    temp_s2 = arg0 + 0x12600;
    temp_s0 = arg0 + 0x137F0;
    ((struct DynamicsConductorTraining__structor_0_arg0 *)arg0)->unk64 = (s32)RaceTraining__vtable;
    temp_s1 = arg0 + 0x23938;
    RaceLicenseBGM__structor_0(temp_s2);
    DynamicsConductorLicense__structor_3(temp_s0);
    temp_s0->unk10140 = (s32)DynamicsConductorTraining__vtable;
    ResultLicense__structor_0(temp_s1);
    RaceLicenseDisplay__structor_0(temp_s4);
    ((struct DynamicsConductorTraining__structor_0_arg0 *)arg0)->unk74 = temp_s2;
    ((struct DynamicsConductorTraining__structor_0_arg0 *)arg0)->unk70 = temp_s0;
    if (func_0033CF48() == 0) {
        func_003E1B28(temp_s1, arg0 + 0xE350);
    }
    func_0038BB50(arg0, temp_s4);
    ((struct DynamicsConductorTraining__structor_0_arg0 *)arg0)->unkD68 = 3;
}
