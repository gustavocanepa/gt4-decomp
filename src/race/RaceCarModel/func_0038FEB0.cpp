extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003EDA10(...) throw();
s32 func_00450AB0(...) throw();
s32 func_00450AD0(...) throw();

void func_0038FEB0(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_00450AB0(arg0 + 0x18);
        return;
    }
    func_00450AD0(arg0 + 0x18);
    func_003EDA10(0);
}

}
