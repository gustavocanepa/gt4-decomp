#include "types.h"
#include "gt4/PhotoModeInput.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055F620();                            /* extern */

extern char PhotoModeInput__vtable[];
void PhotoModeInput__structor_0(struct PhotoModeInput *arg0) {
    func_0055F620();
    arg0->unkD8 = 0;
    arg0->unkD0 = (s32)PhotoModeInput__vtable;
}
