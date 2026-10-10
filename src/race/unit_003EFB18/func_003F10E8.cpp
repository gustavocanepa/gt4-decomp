#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
struct func_003F10E8_arg0 {
    char pad0[0xF8BC];
    s32 unkF8BC;
    s32 unkF8C0;
    char padF8C4[0x30];
    s32 unkF8F4;
};

void func_003F10E8(char *arg0) {
    s32 *var_v0;
    s32 var_v1;

    ((struct func_003F10E8_arg0 *)arg0)->unkF8C0 = 0;
    ((struct func_003F10E8_arg0 *)arg0)->unkF8BC = 0;
    var_v1 = 0xB;
    ((struct func_003F10E8_arg0 *)arg0)->unkF8F4 = -0xB;
    var_v0 = (s32 *)(arg0 + 0xF8F0);
    do {
        var_v1 -= 1;
        *var_v0 = 0;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}

}
