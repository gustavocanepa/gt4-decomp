extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 DynamicsConductor__SetupGlobalStatusPre(...) throw();
void DynamicsConductorFreeRun__InitializeLapTimeCorrection(...) throw();

struct DynamicsConductorFreeRun__virtual_25_arg0 {
    char pad0[0xCBE0];
    u8 unkCBE0;
};

void DynamicsConductorFreeRun__SetupGlobalStatusPre(char *arg0) {
    DynamicsConductor__SetupGlobalStatusPre();
    DynamicsConductorFreeRun__InitializeLapTimeCorrection(arg0);
    if (((struct DynamicsConductorFreeRun__virtual_25_arg0 *)arg0)->unkCBE0 != 0) {
        ((struct DynamicsConductorFreeRun__virtual_25_arg0 *)arg0)->unkCBE0 = 2U;
    }
}

}
