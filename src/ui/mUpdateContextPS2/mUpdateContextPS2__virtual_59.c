#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0026DB30(s32);
s32 func_0055EF50(s32, s32);
f32 mUpdateContextPS2__virtual_59(s32 arg0, s32 arg1, s32 arg2) {
    return (s16)func_0055EF50(func_0026DB30((arg1 * 0xD4) + arg0 + 0x1A0), arg2) * 0.0078125f;
}
