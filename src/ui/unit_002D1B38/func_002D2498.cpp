extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002D2288(...) throw();

struct func_002D2498_arg0 {
    char pad0[0x20];
    s32 unk20;
};

s32 func_002D2498(char *arg0) {
    if (((struct func_002D2498_arg0 *)arg0)->unk20 != 0) {
        func_002D2288();
    }
}

}
