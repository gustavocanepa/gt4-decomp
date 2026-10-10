#include "gt4/MTRGeometry.h"
typedef int s32;
typedef float f32;

extern "C" f32 MTRGeometry__virtual_24(struct MTRGeometry *arg0) {
    f32 var_f0 = 5.0f;
    if (arg0->unk4 != 0) {
        var_f0 = -1.5f;
    }
    return var_f0;
}
