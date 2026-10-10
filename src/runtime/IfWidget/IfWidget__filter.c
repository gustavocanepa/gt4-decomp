#include "types.h"
#include "gt4/IfWidget.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0028EA18(s32);                             /* extern */

s32 IfWidget__filter(struct IfWidget *arg0, s32 *arg1) {
    return func_0028EA18(*arg1) == arg0->unk4;
}
