#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_0035E108(void *, s32);
struct func_0034D418_arg1 {
    char pad0[0x70];
    s32 unk70;
    char pad74[0x68];
    s32 unkDC;
    char padE0[0xC];
    s32 unkEC;
};

struct func_0034D418_arg0 {
    void *unk0;
    char pad4[0xF815];
    s8 unkF819;
    char padF81A[0x36];
    s16 unkF850;
};

void func_0034D418(s8 *arg0, struct func_0034D418_arg1 *arg1) {
    ((struct func_0034D418_arg0 *)arg0)->unk0 = arg1;
    func_0035E108(arg0 + 0xF818, arg1->unk70);
    if ((arg1->unkEC != 0) || (arg1->unkDC != 0)) {
        ((struct func_0034D418_arg0 *)arg0)->unkF819 = 0;
        ((struct func_0034D418_arg0 *)arg0)->unkF850 = 0;
    }
}
