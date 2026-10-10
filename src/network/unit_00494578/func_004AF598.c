#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AEFF0();                            /* extern */
s32 func_004AF688(void *);                      /* extern */
s32 func_004AFBF8(s32);                         /* extern */

extern char D_00688F28[];
struct func_004AF598_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_004AF598(void *arg0) {
    func_004AEFF0();
    ((struct func_004AF598_arg0 *)arg0)->unkA8 = (s32)D_00688F28;
    func_004AFBF8(arg0 + 0xB0);
    func_004AF688(arg0);
}
