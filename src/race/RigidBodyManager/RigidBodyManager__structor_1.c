#include "types.h"
#include "gt4/RigidBodyManager.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005C1628(void *);                      /* extern */
s32 func_005C1648(s32);                         /* extern */

extern char RigidBodyManager__vtable[];
extern char D_006D6054[];
extern char D_006D6060[];
void RigidBodyManager__structor_1(struct RigidBodyManager *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk14 = (s32)RigidBodyManager__vtable;
    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        func_005C1648(temp_v1);
    }
    *(s32 *)D_006D6054 = 0;
    *(s32 *)D_006D6060 = 0;
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
