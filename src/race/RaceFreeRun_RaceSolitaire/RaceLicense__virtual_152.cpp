#include "gt4/RaceLicense.h"
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" void func_003BDB48(s32 arg0);

extern "C" void RaceLicense__virtual_152(struct RaceLicense *arg0)
{
    VEntry *e = (VEntry *)(arg0->unk64 + 0x90);

    func_003BDB48(e->fn((char *)arg0 + e->delta));
}
