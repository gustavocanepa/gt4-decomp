#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00358440_arg0 {
    char pad0[0xF898];
    u32 unkF898;
};

u32 DynamicsConductor__CurrentTotalTime(struct func_00358440_arg0 *arg0) {
    return (u32) arg0->unkF898 / 3U;
}
