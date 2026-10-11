#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct DynamicsConductorBattle2P__virtual_08_arg1 {
    char pad0[0x5B8];
    u8 unk5B8;
};

u8 DynamicsConductor__getDataLoggerSection(s32 arg0, struct DynamicsConductorBattle2P__virtual_08_arg1 *arg1) {
    return arg1->unk5B8;
}
