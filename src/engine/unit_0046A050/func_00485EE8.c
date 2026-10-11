#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void free(s32);
struct func_00485EE8_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00485EE8(struct func_00485EE8_arg0 *arg0) {
    s32 temp_v0;
    if (arg0->unk4 != 0) {
        temp_v0 = arg0->unk0;
        if (temp_v0 != 0) {
            free(temp_v0);
        }
    }
    arg0->unk0 = 0;
    arg0->unk4 = 0;
}
