extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004EF8E8(...) throw();

u32 func_004EF410(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (u32) ~func_004EF8E8(arg0, arg2, arg3, arg1) >> 0x1F;
}

}
