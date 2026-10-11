#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_0034C190(s32, s32);
void RaceDisplayEventBase__put(void *, void *);
void RaceDisplayInformationEvent__structor_0(void *);
struct func_0035E000_arg0_unk84 {
    char pad0[0x70];
    s32 unk70;
};
struct func_0035E000_arg0 {
    char pad0[0x84];
    struct func_0035E000_arg0_unk84 *unk84;
    char pad88[0x54];
    s32 unkDC;
};

void func_0035E000(struct func_0035E000_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    if ((M2C_FIELD(func_0034C190(arg0->unk84->unk70, arg1), u8 *, 0x736) == 0) && (arg0->unkDC == 0)) {
        RaceDisplayInformationEvent__structor_0(sp);
        sp[0] = arg1;
        sp[2] = arg2;
        RaceDisplayEventBase__put(sp, arg0);
    }
}
