#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_005CD968(void *);
struct func_003C7010_arg0 {
    char pad0[0x1E650];
    void *unk1E650;
};
struct func_003C7010_temp_s0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_003C7010(struct func_003C7010_arg0 *arg0) {
    struct func_003C7010_temp_s0 *temp_s0;
    temp_s0 = arg0->unk1E650;
    if (temp_s0 != NULL) {
        func_005CD968(temp_s0);
        temp_s0->unk10 = 0;
        temp_s0->unk14 = 0;
    }
}
