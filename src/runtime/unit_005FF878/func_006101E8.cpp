extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00576AD8(...) throw();

struct func_006101E8_arg0 {
    char pad0[0x88];
    s32 unk88;
    s32 unk8C;
};

s32 func_006101E8(char *arg0, s32 *arg1, s32 *arg2) {
    func_00576AD8(arg0 + 0x80, 0x40);
    *arg1 = ((struct func_006101E8_arg0 *)arg0)->unk88;
    *arg2 = ((struct func_006101E8_arg0 *)arg0)->unk8C;
}

}
