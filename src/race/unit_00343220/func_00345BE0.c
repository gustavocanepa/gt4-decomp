#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void AutomobileControl__clearPacket(void *);
void func_0057AD40(void *);
struct func_00345BE0_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x20];
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
};

void func_00345BE0(void *arg0) {
    func_0057AD40(arg0);
    ((struct func_00345BE0_arg0 *)arg0)->unk3C = 0;
    ((struct func_00345BE0_arg0 *)arg0)->unk38 = 0;
    ((struct func_00345BE0_arg0 *)arg0)->unk40 = 0;
    ((struct func_00345BE0_arg0 *)arg0)->unk44 = 0;
    ((struct func_00345BE0_arg0 *)arg0)->unk14 = 0;
    AutomobileControl__clearPacket((s8 *)arg0 + 0x18);
    if (((struct func_00345BE0_arg0 *)arg0)->unk48 == 0) {
        ((struct func_00345BE0_arg0 *)arg0)->unk38 = 1;
    }
}
