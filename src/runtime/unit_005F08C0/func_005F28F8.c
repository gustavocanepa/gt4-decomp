#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceInformation__structor_0();                            /* extern */
s32 func_003D6268(void *);                      /* extern */

extern char D_00677B80[];
struct func_005F28F8_arg0 {
    char pad0[0x12C];
    s32 unk12C;
    char pad130[0x328];
    s32 unk458;
};

void func_005F28F8(void *arg0) {
    RaceInformation__structor_0();
    ((struct func_005F28F8_arg0 *)arg0)->unk12C = (s32)D_00677B80;
    func_003D6268(arg0 + 0x130);
    func_003D6268(arg0 + 0x2C0);
    ((struct func_005F28F8_arg0 *)arg0)->unk458 = 0;
}
