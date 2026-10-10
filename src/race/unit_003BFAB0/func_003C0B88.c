#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00447670(s32);
s32 func_004476B0(s32);
s32 func_004476F0(s32);
struct func_003C0B88_arg0 {
    char pad0[0x70];
    s32 unk70;
};

s32 func_003C0B88(struct func_003C0B88_arg0 *arg0, s32 arg1) {
    switch (arg1) {
    case 1:
        return func_00447670(arg0->unk70);
    case 2:
        return func_004476B0(arg0->unk70);
    case 3:
        return func_004476F0(arg0->unk70);
    }
    return 0;
}
