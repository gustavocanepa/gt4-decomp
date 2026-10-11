#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 *func_00385B48(s32);                            /* extern */
s32 *func_00385B58(s32);                            /* extern */
s32 *func_00385B68(s32);                            /* extern */
s32 *func_00385B98(s32);                            /* extern */

void func_00414578(s32 *arg0) {
    *func_00385B48(*arg0) = 0;
    *func_00385B98(*arg0) = 0;
    *func_00385B58(*arg0) = 0;
    *func_00385B68(*arg0) = 0;
}
