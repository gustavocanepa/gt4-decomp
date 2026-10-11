extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A609C(...) throw();
s32 func_005A6CF8(...) throw();

void func_0030D110(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_005A6CF8(arg1, 0x2F);
    if (temp_v0 != 0) {
        func_005A609C(arg0, temp_v0 + 1);
        return;
    }
    func_005A609C(arg0, arg1);
}

}
