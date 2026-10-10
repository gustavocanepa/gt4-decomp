#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 CameraBase__structor_0();                            /* extern */

extern char D_006792D8[];
struct func_005F3738_arg0 {
    s32 unk0;
    char pad4[0x88];
    s32 unk8C;
    s32 unk90;
};

void func_005F3738(struct func_005F3738_arg0 *arg0) {
    CameraBase__structor_0();
    arg0->unk90 = 0;
    arg0->unk8C = 0;
    arg0->unk0 = (s32)D_006792D8;
}
