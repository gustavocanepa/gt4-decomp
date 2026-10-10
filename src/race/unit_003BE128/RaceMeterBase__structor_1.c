#include "types.h"
#include "gt4/RaceMeterBase.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char RaceMeterBase__vtable[];
s32 RaceDisplayObjectBase__structor_0(void *);
void RaceMeterBase__structor_1(struct RaceMeterBase *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    arg0->unk14 = (s32)RaceMeterBase__vtable;
    arg0->unk0 = (s32) ((arg0->unk0 & ~0xFF) | 1);
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk18 = 0;
}
