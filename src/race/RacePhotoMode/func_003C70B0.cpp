#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00394BE8(s32);                         /* extern */
s32 func_00394ED8(s32, s64);                    /* extern */

struct func_003C70B0_arg0 {
    char pad0[0x6C];
    void *unk6C;
    char pad70[0x1E5E4];
    s32 unk1E654;
};
struct func_003C70B0_temp_v0_2 {
    char pad0[0x78];
    s64 unk78;
    s32 unk80;
};

void func_003C70B0(void *arg0) {
    s32 temp_v0;
    void *temp_v0_2;

    temp_v0 = ((struct func_003C70B0_arg0 *)arg0)->unk1E654;
    if (temp_v0 != 0) {
        func_00394BE8(temp_v0);
    }
    temp_v0_2 = ((struct func_003C70B0_arg0 *)arg0)->unk6C;
    ((struct func_003C70B0_arg0 *)arg0)->unk1E654 = 0;
    func_00394ED8(((struct func_003C70B0_temp_v0_2 *)temp_v0_2)->unk80, ((struct func_003C70B0_temp_v0_2 *)temp_v0_2)->unk78);
}
