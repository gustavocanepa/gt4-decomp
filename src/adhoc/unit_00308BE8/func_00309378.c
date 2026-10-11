#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005C1628(void *);                      /* extern */

void func_00309378(void *arg0, s32 arg1) {
    func_00328798((s32 *) arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
