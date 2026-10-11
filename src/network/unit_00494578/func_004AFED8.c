/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004AD368(s32, void *);                 /* extern */
void *func_004AE1F8(s32);                           /* extern */
s32 func_004AF7D0(void *);                          /* extern */
s32 func_004AFFB8(void *);                      /* extern */

struct func_004AFED8_temp_v0_2 {
    char pad0[0x4C];
    void *unk4C;
};
struct func_004AFED8_temp_a1 {
    char pad0[0x38];
    s32 unk38;
};

struct func_004AFED8_arg0 {
    s32 unk0;
    void *unk4;
};

s32 func_004AFED8(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    struct func_004AFED8_temp_a1 *temp_a1;
    struct func_004AFED8_temp_v0_2 *temp_v0_2;

    temp_v0_2 = func_004AE1F8(arg0 + 0x24);
    ((struct func_004AFED8_arg0 *)arg0)->unk4 = temp_v0_2;
    if (temp_v0_2 != NULL) {
        temp_v0_2->unk4C = arg0;
        M2C_FIELD(((struct func_004AFED8_arg0 *)arg0)->unk4, s32 *, 0x74) = arg2;
        temp_a1 = ((struct func_004AFED8_arg0 *)arg0)->unk4;
        func_004AD368(temp_a1->unk38, temp_a1);
        temp_v0 = func_004AF7D0(arg0);
        if (temp_v0 < 0) {
            func_004AFFB8(arg0);
        }
        return temp_v0;
    }
    ((struct func_004AFED8_arg0 *)arg0)->unk0 = 2;
    return -1;
}
