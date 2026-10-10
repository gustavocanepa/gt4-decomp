#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00562E90(void *);                      /* extern */
s32 func_005ADCC0(s32);                         /* extern */
s32 func_005ADCE0(s32);                         /* extern */

struct func_00550488_arg0 {
    char pad0[0x38];
    s32 unk38;
};

s32 func_00550488(struct func_00550488_arg0 *arg0) {
    func_005ADCE0(arg0->unk38);
    func_00562E90(arg0);
    func_005ADCC0(arg0->unk38);
    return 0;
}
