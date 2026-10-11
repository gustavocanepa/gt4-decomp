#include "types.h"
#include "gt4/mTextBoxFace.h"
void *memcpy(void *, const void *, unsigned int);

f32 mTextBoxFace__getBeginPointRatio(struct mTextBoxFace *arg0) {
    f32 temp_f2;
    f32 var_f0;

    temp_f2 = (f32) arg0->unk3AC;
    var_f0 = ((temp_f2 - arg0->unk3BC) - (f32) arg0->unk3B0) / temp_f2;
    if (var_f0 < 0.0f) {
        var_f0 = 0.0f;
    }
    return var_f0;
}
