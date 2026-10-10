extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003C0FF0(...) throw();
s32 func_004336D0(...) throw();
s32 func_00433C10(...) throw();
s32 func_004472A0(...) throw();

extern char D_00622F4C[];
struct func_00111E98_arg0 {
    char pad0[0x6C];
    char *unk6C;
    char pad70[0xC58];
    s32 unkCC8;
};
struct func_00111E98_temp_s1 {
    char pad0[0x60];
    char *unk60;
    char pad64[0xC];
    s32 unk70;
};

s32 func_00111E98(char *arg0) {
    s32 temp_s0;
    s32 temp_v1;
    s32 var_a1;
    char *temp_s1;

    temp_v1 = ((struct func_00111E98_arg0 *)arg0)->unkCC8;
    var_a1 = 0;
    if ((temp_v1 == 0) || (temp_v1 == 2)) {
        var_a1 = 1;
    }
    temp_s1 = ((struct func_00111E98_arg0 *)arg0)->unk6C;
    if ((M2C_FIELD(M2C_FIELD(*M2C_FIELD(((struct func_00111E98_temp_s1 *)temp_s1)->unk60, char ***, 8), char **, 0x18), u8 *, 0x5B6) != 0) && (var_a1 != 0)) {
        temp_s0 = func_003C0FF0(temp_s1, 0);
        func_004336D0(func_00433C10(*(s32 *)D_00622F4C + 0x14A30, func_004472A0(((struct func_00111E98_temp_s1 *)temp_s1)->unk70)), temp_s0);
    }
}

}
