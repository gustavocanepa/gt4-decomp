#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00109478(s32, void *);                 /* extern */

struct CarIconMaker__virtual_09_temp_a1 {
    char pad0[0xC];
    s32 unkC;
};
struct CarIconMaker__virtual_09_temp_s0 {
    char pad0[0xC];
    s32 unkC;
};

void CarIconMaker__virtual_09(s32 arg0) {
    char *temp_a1;
    char *temp_s0;

    temp_a1 = (char *)(arg0 + 0x30);
    temp_s0 = (char *)(arg0 + 0x44);
    func_00109478(((struct CarIconMaker__virtual_09_temp_a1 *)temp_a1)->unkC, temp_a1);
    func_00109478(((struct CarIconMaker__virtual_09_temp_s0 *)temp_s0)->unkC, temp_s0);
}

}
