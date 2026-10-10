#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

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
struct DynamicsConductorFreeRun {
    struct RaceDisplayTimeDiffEvent * unk0;
    char unk_4[0x90];
    f32 unk94;
};
s32 func_0034C190(s32, s32);
s32 func_0035DF80(struct RaceDisplayTimeDiffEvent *, s32, s32, s32); /* extern */
s32 Automobile__CountDownRollingStartTimer(s32);                             /* extern */

void DynamicsConductorFreeRun__ProcessLapTimeCommonPre(struct DynamicsConductorFreeRun *arg0) {
    s32 temp_v0;

    temp_v0 = func_0034C190((s32) arg0, 0);
    if (Automobile__CountDownRollingStartTimer(temp_v0) != 0) {
        func_00345228((void *) temp_v0);
        func_0035DF80(arg0->unk0, 4, 0, 0);
    }
}
