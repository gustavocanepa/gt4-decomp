#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004EAE50();                            /* extern */
s32 func_004EB4E0();                            /* extern */

struct func_004EB770_arg0 {
    char pad0[0xD0];
    s32 unkD0;
};

void func_004EB770(struct func_004EB770_arg0 *arg0) {
    if (arg0->unkD0 == 0) {
        func_004EAE50();
        return;
    }
    func_004EB4E0();
}
