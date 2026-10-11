/* compiler: ee-gcc2.96-nosched1 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK PauseBase__clearTimeCount();                            /* extern */

void PhotoPause__init(void *arg0) {
    PauseBase__clearTimeCount();
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1AC) = -1;
    M2C_FIELD(arg0, s32 *, 0x198) = -1;
    M2C_FIELD(arg0, s32 *, 0x1A4) = 0;
    M2C_FIELD(arg0, s32 *, 0x1A8) = 0;
}
