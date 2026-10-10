extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 DynamicsConductorBattle2P__virtual_25(...) throw();
void func_003F5718(...) throw();

struct DynamicsConductorFreeRun__virtual_25_arg0 {
    char pad0[0xCBE0];
    u8 unkCBE0;
};

void DynamicsConductorFreeRun__virtual_25(char *arg0) {
    DynamicsConductorBattle2P__virtual_25();
    func_003F5718(arg0);
    if (((struct DynamicsConductorFreeRun__virtual_25_arg0 *)arg0)->unkCBE0 != 0) {
        ((struct DynamicsConductorFreeRun__virtual_25_arg0 *)arg0)->unkCBE0 = 2U;
    }
}

}
