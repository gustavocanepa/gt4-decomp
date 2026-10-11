extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A1638(...) throw();
s32 pglFrontFace(...) throw();
s32 func_004AB040(...) throw();

void func_00473338(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        func_004A1638(0xF);
        pglFrontFace(arg2 != 0);
        return;
    }
    func_004AB040(0xF);
}

}
