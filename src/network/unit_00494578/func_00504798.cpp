extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00504630(...) throw();
s32 func_00504650(...) throw();

struct func_00504798_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00504798(char *arg0) {
    if (((struct func_00504798_arg0 *)arg0)->unk4 != 0) {
        func_00504630(3);
        return;
    }
    if (((struct func_00504798_arg0 *)arg0)->unk0 == 0) {
        func_00504630(3);
        return;
    }
    func_00504650(arg0 + 8);
    func_00504630(1);
}

}
