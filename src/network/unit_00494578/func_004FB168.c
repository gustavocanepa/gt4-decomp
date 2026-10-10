#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_004FB168_arg0 {
    char pad0[0xFCC];
    s32 unkFCC;
};

s32 func_004FB168(struct func_004FB168_arg0 *arg0) {
    return (u32) (arg0->unkFCC - 5) < 2U;
}
