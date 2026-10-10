/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00490CE0(s32);                         /* extern */

extern char PDISTD__global_font_manager[];
void func_0044D988(s32 *arg0) {
    if (*arg0 != 0) {
        *arg0 = 0;
        func_00490CE0(*(s32 *)PDISTD__global_font_manager);
    }
}
