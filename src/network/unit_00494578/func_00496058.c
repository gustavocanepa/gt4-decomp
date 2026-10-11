#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00496018();                                /* extern */

f32 func_00496058(f32 fparg0, f32 fparg1) {
    return ((func_00496018() - 1.0f) * (fparg1 - fparg0)) + fparg0;
}
