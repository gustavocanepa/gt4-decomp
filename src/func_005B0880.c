/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_008869C0[];
s32 func_005B0880(s32 arg0) {
    return *(s32 *)((s32)D_008869C0 + (arg0 * 4));
}
