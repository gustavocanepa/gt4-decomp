extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_004A5400(...) throw();

struct func_0042C7C8_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_0042C7C8(char *arg0) {
    s32 temp_v0;

    if (((struct func_0042C7C8_arg0 *)arg0)->unk8 > 0) {
        do {
            func_004A5400();
            temp_v0 = ((struct func_0042C7C8_arg0 *)arg0)->unk8 - 1;
            ((struct func_0042C7C8_arg0 *)arg0)->unk8 = temp_v0;
        } while (temp_v0 > 0);
    }
    ((struct func_0042C7C8_arg0 *)arg0)->unk0 = 1;
}

}
