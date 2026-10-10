#include "types.h"
#include "gt4/RaceMachineTest.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0038BB50(void *, void *);              /* extern */
s32 func_00393700(s32);                         /* extern */
s32 RaceDisplay__structor_0(void *);                      /* extern */
s32 RacePause__structor_0(void *);                      /* extern */
s32 func_003C31C8(void *, void *);              /* extern */
s32 ResultArcade__structor_0(void *);                      /* extern */
s32 func_003DF898(void *, void *);              /* extern */
s32 RaceSolitaire__structor_0();                            /* extern */
s32 DynamicsConductorMachineTest__structor_1(void *);                      /* extern */

extern char RaceMachineTest__vtable[];
struct RaceMachineTest__structor_0_temp_s0 {
    char pad0[0x28];
    s32 unk28;
};

void RaceMachineTest__structor_0(void *arg0) {
    s32 temp_a0;
    s32 var_s0;
    s32 var_s1;
    struct RaceMachineTest__structor_0_temp_s0 *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;

    var_s1 = 5;
    var_s0 = arg0 + 0xF140;
    RaceSolitaire__structor_0();
    ((struct RaceMachineTest *)arg0)->unk64 = (s32)RaceMachineTest__vtable;
    do {
        temp_a0 = var_s0;
        var_s0 += 8;
        var_s1 -= 1;
        func_00393700(temp_a0);
    } while (var_s1 != -1);
    temp_s0 = arg0 + 0xF170;
    temp_s4 = arg0 + 0xF1A8;
    temp_s2 = arg0 + 0xF6A8;
    RacePause__structor_0(temp_s0);
    ResultArcade__structor_0(temp_s4);
    RaceDisplay__structor_0(temp_s2);
    temp_s1 = arg0 + 0x135D8;
    temp_s3 = arg0 + 0xE350;
    DynamicsConductorMachineTest__structor_1(temp_s1);
    func_0038BB50(arg0, temp_s2);
    ((struct RaceMachineTest *)arg0)->unk70 = temp_s1;
    temp_s0->unk28 = 1;
    func_003C31C8(temp_s0, temp_s3);
    func_003DF898(temp_s4, temp_s3);
    ((struct RaceMachineTest *)arg0)->unkD68 = 0xF;
}
