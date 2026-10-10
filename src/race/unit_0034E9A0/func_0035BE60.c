#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0035BC70();                            /* extern */
s32 func_0035BE10(void *);                      /* extern */

struct func_0035BE60_arg0 {
    char pad0[0x56A];
    s8 unk56A;
};

void func_0035BE60(struct func_0035BE60_arg0 *arg0) {
    if (arg0->unk56A == 2) {
        return;
    }
    func_0035BC70();
    func_0035BE10(arg0);
}
