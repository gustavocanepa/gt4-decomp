#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005C2418();                            /* extern */

extern char D_00659F90[];
struct func_00109448_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_00109448(struct func_00109448_arg0 *arg0) {
    func_005C2418();
    arg0->unk8 = (s32)D_00659F90;
}
