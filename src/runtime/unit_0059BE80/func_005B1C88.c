/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005B72A8();                            /* extern */
s32 func_005B72F8();                            /* extern */

struct func_005B1C88_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x4];
    s32 unk10;
    s32 unk14;
    char pad18[0x20];
    void *unk38;
    void *unk3C;
    void *unk40;
};
struct func_005B1C88_arg6 {
    char pad0[0x8];
    void *unk8;
};
struct func_005B1C88_var_a0 {
    char pad0[0x38];
    void *unk38;
};

void func_005B1C88(struct func_005B1C88_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, struct func_005B1C88_arg6 *arg6) {
    void *temp_v0;
    void *temp_v0_2;
    struct func_005B1C88_var_a0 *var_a0;
    void *var_v1;

    func_005B72A8();
    arg0->unk3C = 0;
    arg0->unk38 = 0;
    arg0->unk0 = arg1;
    temp_v0 = arg6->unk8;
    arg0->unk4 = arg2;
    arg0->unk8 = arg3;
    arg0->unk10 = arg4;
    arg0->unk14 = arg5;
    arg0->unk40 = arg6;
    if (temp_v0 == NULL) {
        arg6->unk8 = arg0;
    } else {
        var_a0 = temp_v0;
        var_v1 = var_a0->unk38;
        if (var_v1 != NULL) {
            do {
                var_a0 = var_v1;
                temp_v0_2 = var_a0->unk38;
                var_v1 = temp_v0_2;
            } while (temp_v0_2 != NULL);
        }
        var_a0->unk38 = arg0;
    }
    func_005B72F8();
}
