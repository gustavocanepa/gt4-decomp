extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 free(...) throw();
void func_00611108(...) throw();

struct func_00557EC0_arg0 {
    char pad0[0x75C];
    s32 unk75C;
    s32 unk760;
    s32 unk764;
};

void func_00557EC0(char *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;

    func_00611108(arg0 + 0x630);
    temp_v0 = ((struct func_00557EC0_arg0 *)arg0)->unk75C;
    if (temp_v0 != 0) {
        free(temp_v0);
    }
    temp_a0 = ((struct func_00557EC0_arg0 *)arg0)->unk760;
    ((struct func_00557EC0_arg0 *)arg0)->unk75C = 0;
    if (temp_a0 != 0) {
        free(temp_a0);
    }
    temp_a0_2 = ((struct func_00557EC0_arg0 *)arg0)->unk764;
    ((struct func_00557EC0_arg0 *)arg0)->unk760 = 0;
    if (temp_a0_2 != 0) {
        free(temp_a0_2);
    }
    ((struct func_00557EC0_arg0 *)arg0)->unk764 = 0;
}

}
