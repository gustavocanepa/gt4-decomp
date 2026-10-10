#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00105250(void *);
void func_00107AE8(void *);
void Ipic__structor_0(void *);
struct func_001FD2A8_arg0 {
    char pad0[0x8C];
    s32 unk8C;
    char pad90[0x18];
    s32 unkA8;
    char padAC[0x8];
    s32 unkB4;
    char padB8[0x1C];
    s32 unkD4;
    s32 unkD8;
    s32 unkDC;
    s32 unkE0;
};

void func_001FD2A8(void *arg0) {
    func_00105250(arg0);
    func_00107AE8((s8 *)arg0 + 0x40);
    ((struct func_001FD2A8_arg0 *)arg0)->unk8C = 0;
    ((struct func_001FD2A8_arg0 *)arg0)->unkA8 = 0;
    ((struct func_001FD2A8_arg0 *)arg0)->unkB4 = 0;
    Ipic__structor_0((s8 *)arg0 + 0xB8);
    ((struct func_001FD2A8_arg0 *)arg0)->unkD4 = 0;
    ((struct func_001FD2A8_arg0 *)arg0)->unkD8 = 0;
    ((struct func_001FD2A8_arg0 *)arg0)->unkDC = 0;
    ((struct func_001FD2A8_arg0 *)arg0)->unkE0 = 0;
}
