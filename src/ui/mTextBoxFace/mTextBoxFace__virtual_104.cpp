#include "gt4/mTextBoxFace.h"
typedef int s32;
typedef float f32;

extern "C" f32 mTextBoxFace__virtual_104(struct mTextBoxFace *arg0) {
    f32 var_f0;

    var_f0 = (f32)arg0->unk3B0 / (f32)arg0->unk3AC;
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
    }
    return var_f0;
}
