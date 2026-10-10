#include "types.h"
#include "gt4/mLoggerFace.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0011FF38(s32, s32, void *);            /* extern */
s32 mTextFace__virtual_67();                            /* extern */

s32 mLoggerFace__virtual_67(struct mLoggerFace *arg0, s32 arg1) {
    s32 temp_v0;

    mTextFace__virtual_67();
    temp_v0 = arg0->unkA4;
    arg0->unkA0 = arg1;
    if (temp_v0 != 0) {
        func_0011FF38(temp_v0, arg1, arg0);
    }
}
