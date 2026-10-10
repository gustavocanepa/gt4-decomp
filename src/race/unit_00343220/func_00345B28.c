#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00679970[];
void func_0057AD08(void *, s32);
void func_005C1628(void *);
struct func_00345B28_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_00345B28(struct func_00345B28_arg0 *arg0, s32 arg1) {
    arg0->unk50 = (s32)D_00679970;
    func_0057AD08(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
