#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004CEC70_var_a1 {
    char pad0[0x4];
    void *unk4;
};
struct func_004CEC70_temp_v1 {
    char pad0[0x4];
    void *unk4;
};
struct func_004CEC70_arg0 {
    char pad0[0x17C];
    void *unk17C;
};

void func_004CEC70(struct func_004CEC70_arg0 *arg0, void *arg1) {
    struct func_004CEC70_temp_v1 *temp_v1;
    struct func_004CEC70_var_a1 *var_a1;

    var_a1 = arg1;
    if (var_a1 != NULL) {
        do {
            temp_v1 = var_a1;
            var_a1 = var_a1->unk4;
            temp_v1->unk4 = (void *) arg0->unk17C;
            arg0->unk17C = temp_v1;
        } while (var_a1 != NULL);
    }
}
