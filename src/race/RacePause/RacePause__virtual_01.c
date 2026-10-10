#include "types.h"
#include "gt4/RacePause.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003C65D0();                            /* extern */
s32 func_00474F38(void *, s32, s32, s32);   /* extern */
s32 func_00475D78(void *, s32, void *);     /* extern */
void *exception__structor_0(s32);                       /* extern */

extern char D_003C2F98[];
void RacePause__virtual_01(struct RacePause *arg0) {
    void *temp_v0;

    func_003C65D0();
    arg0->unkC = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    if (arg0->unk10 != 0) {
        temp_v0 = exception__structor_0(0x19C);
        func_00474F38(temp_v0, arg0->unk10, 0, arg0->unk18);
        arg0->unk14_pvoid = temp_v0;
        func_00475D78(temp_v0, (s32)D_003C2F98, arg0);
        M2C_FIELD(arg0->unk14_pvoid, s32 *, 0x10) = 1;
    }
}
