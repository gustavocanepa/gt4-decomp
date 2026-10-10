#include "types.h"
#include "gt4/mComm.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001DC5F8(void *, s32);             /* extern */
s32 func_001DC8F0(void *);                      /* extern */
s32 hObject__structor_0();                            /* extern */
s32 func_00520C48();                                /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */

extern char mComm__vtable[];
void mComm__structor_0(void *arg0) {
    s8 sp[0x10];
    hObject__structor_0();
    ((struct mComm *)arg0)->unk4 = (s32)mComm__vtable;
    func_001DC8F0(sp);
    ((struct mComm *)arg0)->unk20 = func_00520C48();
    ((struct mComm *)arg0)->unk10 = 0;
    func_005A48D8(arg0 + 0x14, 0, 0xC);
    ((struct mComm *)arg0)->unk14 = 0;
    ((struct mComm *)arg0)->unk20 = 0;
    func_001DC5F8(sp, 2);
}
