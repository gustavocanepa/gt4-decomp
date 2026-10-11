#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 fflush();                                /* extern */

struct func_005A5668_arg0 {
    char pad0[0xC];
    u16 unkC;
};

s32 func_005A5668(struct func_005A5668_arg0 *arg0) {
    if ((arg0->unkC & 9) == 9) {
        return fflush();
    }
    return 0;
}
