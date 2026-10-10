#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct DynamicsConductorFreeRun {
    struct RaceDisplayTimeDiffEvent * unk0;
    char unk_4[0x90];
    f32 unk94;
};
struct RaceDisplayTimeDiffEvent {
    void * unk0;
    void * unk4;
    s32 unk8;
    s32 unkC;
    char unk_10[0x74];
    void * unk84;
    char unk_88[0x34];
    f32 unkBC;
};
s32 func_0034C190(s32, s32);
s32 RaceDisplayGeneralTimeEvent__structor_0(struct DynamicsConductorFreeRun *, s32, s32, s32, s32, s32, u8); /* extern */
s32 func_0035E6B0(struct DynamicsConductorFreeRun *, s32, s32, s32); /* extern */

struct DynamicsConductorFreeRun__virtual_18_temp_s2 {
    char pad0[0x5B7];
    u8 unk5B7;
};

void DynamicsConductorFreeRun__ProcessCheckPoint(struct DynamicsConductorFreeRun *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_s2;

    temp_s2 = func_0034C190((s32) arg0, arg1);
    func_0035E6B0(arg0, arg1, arg3, arg6);
    RaceDisplayGeneralTimeEvent__structor_0(arg0, arg1, arg2 - 1, arg3, arg5, arg6, ((struct DynamicsConductorFreeRun__virtual_18_temp_s2 *)temp_s2)->unk5B7);
}
