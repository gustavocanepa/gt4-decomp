extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(...) throw();

struct func_0054F7A0_arg0 {
    char pad0[0x4];
    char *unk4;
    char *unk8;
    char *unkC;
};

void func_0054F7A0(char *arg0) {
    func_00575DA0(((struct func_0054F7A0_arg0 *)arg0)->unkC);
    func_00575DA0(((struct func_0054F7A0_arg0 *)arg0)->unk8);
    func_00575DA0(((struct func_0054F7A0_arg0 *)arg0)->unk4);
    func_00575DA0(arg0);
}

}
