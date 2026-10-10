#include "gt4/PGLXshapeBuilder.h"
typedef int s32;

extern char PGLXshapeBuilder__vtable[];
extern "C" s32 func_004945C0(struct PGLXshapeBuilder *arg0);

extern "C" s32 PGLXshapeBuilder__structor_0(struct PGLXshapeBuilder *arg0) {
    arg0->unk98C = PGLXshapeBuilder__vtable;
    return func_004945C0(arg0);
}
