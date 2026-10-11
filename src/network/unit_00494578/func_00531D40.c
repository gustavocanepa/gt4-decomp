#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00531D40_temp_v0 {
    char pad0[0x20];
    s32 unk20;
};

s32 func_00531D40(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_v0;
    u32 var_v1;
    struct func_00531D40_temp_v0 *temp_v0;

    var_a1 = arg1;
    var_v1 = 0;
    var_v0 = 0x17;
    if (arg0 != 0) {
        *(s32 *)arg0 = 0;
        if (var_a1 != 0) {
            do {
                temp_v0 = *(s32 *)var_a1;
                var_a1 += 4;
                if ((temp_v0 != NULL) && (temp_v0->unk20 != 0)) {
                    *(s32 *)arg0 = (s32) (*(s32 *)arg0 + 1);
                }
                var_v1 += 1;
            } while (var_v1 < 0x40U);
            var_v0 = 0;
        }
    }
    return var_v0;
}
