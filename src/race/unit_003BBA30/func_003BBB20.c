#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_003BBB20_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

s32 func_003BBB20(void *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = ((struct func_003BBB20_arg0 *)arg0)->unk8;
    if ((arg1 >= temp_v1) && (arg1 < (temp_v1 + ((struct func_003BBB20_arg0 *)arg0)->unkC))) {
        return M2C_FIELD((((arg1 - temp_v1) * 4) + arg0), s32 *, 0x14);
    }
    return 0;
}
