extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00437EF0(...) throw();
s32 func_00437F58(...) throw();

struct func_00437EB8_arg0 {
    char pad0[0x6];
    u8 unk6;
};

void func_00437EB8(char *arg0) {
    if (((struct func_00437EB8_arg0 *)arg0)->unk6 == 0) {
        func_00437EF0();
        return;
    }
    func_00437F58();
}

}
