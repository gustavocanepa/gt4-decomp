#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00472940(s32 *p, f32 x) {
    switch (*p) {
    case 0: return x * 0x1.CCCCCCp+1f;
    case 1: return x * 0x1.CCCCCCp+1f * 0x1.3E26D4p-1f;
    }
    return x;

}
