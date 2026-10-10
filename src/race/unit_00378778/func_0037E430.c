#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00378AE0();                            /* extern */

extern char D_0067AF48[];
struct func_0037E430_arg0 {
    s32 unk0;
    char pad4[0x188];
    s32 unk18C;
};

void func_0037E430(struct func_0037E430_arg0 *arg0) {
    func_00378AE0();
    arg0->unk18C = 0;
    arg0->unk0 = (s32)D_0067AF48;
}
