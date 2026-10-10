#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0033CF48();                                /* extern */
s32 func_00393700(s32);                         /* extern */
s32 ResultArcade__structor_0(void *);                      /* extern */
s32 func_003DF898(void *, void *);              /* extern */
s32 RaceTrainingBase__structor_0();                            /* extern */
s32 DynamicsConductorLicense__structor_3(void *);                      /* extern */

extern char RaceMission__vtable[];
extern char DynamicsConductorMission__vtable[];
struct DynamicsConductorMission__structor_0_temp_s0 {
    char pad0[0x10140];
    s32 unk10140;
};

struct DynamicsConductorMission__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    void *unk70;
    char pad74[0xCF4];
    s32 unkD68;
};

s32 DynamicsConductorMission__structor_0(void *arg0) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_s3;
    struct DynamicsConductorMission__structor_0_temp_s0 *temp_s0;
    void *temp_s0_2;

    var_s3 = 5;
    RaceTrainingBase__structor_0();
    temp_s0 = arg0 + 0x12600;
    var_s1 = arg0 + 0x22748;
    ((struct DynamicsConductorMission__structor_0_arg0 *)arg0)->unk64 = (s32)RaceMission__vtable;
    DynamicsConductorLicense__structor_3(temp_s0);
    temp_s0->unk10140 = (s32)DynamicsConductorMission__vtable;
    do {
        temp_a0 = var_s1;
        var_s1 += 8;
        var_s3 -= 1;
        func_00393700(temp_a0);
    } while (var_s3 != -1);
    temp_s0_2 = arg0 + 0x22778;
    ResultArcade__structor_0(temp_s0_2);
    ((struct DynamicsConductorMission__structor_0_arg0 *)arg0)->unk70 = (void *) (arg0 + 0x12600);
    if (func_0033CF48() == 0) {
        func_003DF898(temp_s0_2, arg0 + 0xE350);
    }
    ((struct DynamicsConductorMission__structor_0_arg0 *)arg0)->unkD68 = 0xA;
}
