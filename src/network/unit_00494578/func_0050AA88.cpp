extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050A9C0(...) throw();
s32 func_0050A9E0(...) throw();

struct func_0050AA88_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_0050AA88(char *arg0) {
    if (((struct func_0050AA88_arg0 *)arg0)->unk4 != 0) {
        func_0050A9C0(2);
        return;
    }
    if (((struct func_0050AA88_arg0 *)arg0)->unk0 == 0) {
        func_0050A9C0(2);
        return;
    }
    func_0050A9E0(arg0 + 8);
    func_0050A9C0(1);
}

}
