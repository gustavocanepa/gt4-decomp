#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00447CA0(s64, s32);                    /* extern */

void func_00430808(s64 *arg0, s64 arg1) {
    *arg0 = arg1;
    func_00447CA0(arg1, (s32)(arg0 + 1));
}

}
