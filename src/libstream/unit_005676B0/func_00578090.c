#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005783A0(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00689E60[];
struct func_00578090_arg0 {
    s32 unk0;
    char pad4[0x34];
    s32 unk38;
};

void func_00578090(struct func_00578090_arg0 *arg0, s32 arg1) {
    arg0->unk38 = (s32)D_00689E60;
    func_005783A0(arg0->unk0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
