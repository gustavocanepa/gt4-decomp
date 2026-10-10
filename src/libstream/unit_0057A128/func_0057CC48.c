#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0057CC48_arg0 {
    char pad0[0x4];
    void *unk4;
};

void *func_0057CC48(struct func_0057CC48_arg0 *arg0) {
    void *temp_s0;

    temp_s0 = arg0->unk4;
    if (temp_s0 != NULL) {
        func_0057CB80(arg0, temp_s0);
    }
    return temp_s0;
}
