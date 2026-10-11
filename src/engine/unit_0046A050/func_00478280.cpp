#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00476B78(s32, f32);                    /* extern */
f32 func_00477460(...);                             /* extern */

void func_00478280(s32 arg0, s32 arg1) {
    f32 temp_f20;

    temp_f20 = func_00477460();
    func_00476B78(arg0, temp_f20 - func_00477460(arg1));
}

}
