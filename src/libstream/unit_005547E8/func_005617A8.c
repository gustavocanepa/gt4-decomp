/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { char b[24]; } Block24;
struct func_005617A8_arg0 {
    char pad0[0x5C];
    s32 unk5C;
    char pad60[0x1E0];
    s32 unk240;
};

void func_005617A8(void *arg0) {
    s32 var_a1;
    s32 var_a2;
    void *temp_v0;
    void *var_v1;

    var_a2 = 0;
    if (((struct func_005617A8_arg0 *)arg0)->unk5C > 0) {
        var_v1 = arg0 + 0x70;
        var_a1 = 0;
        do {
            var_a2 += 1;
            temp_v0 = var_a1 + ((struct func_005617A8_arg0 *)arg0)->unk240;
            var_a1 += 0x18;
            *(Block24 *)temp_v0 = *(Block24 *)var_v1;
            var_v1 += 0x18;
        } while (var_a2 < ((struct func_005617A8_arg0 *)arg0)->unk5C);
    }
}
