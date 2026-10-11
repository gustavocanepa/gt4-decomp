#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A3F8();                            /* extern */
s32 func_005797A8(s32, s32, s32);       /* extern */
s32 func_006009C8(s32);                         /* extern */

extern char D_00687908[];
struct func_0042EF90_arg0 {
    s32 unk0;
    char pad4[0xB6BC];
    s32 unkB6C0;
    s32 unkB6C4;
};

s32 func_0042EF90(void *arg0) {
    s32 temp_v0;

    func_0043A3F8();
    ((struct func_0042EF90_arg0 *)arg0)->unk0 = (s32)D_00687908;
    func_006009C8(arg0 + 8);
    temp_v0 = func_005797A8(0x7D5, 4, 2);
    ((struct func_0042EF90_arg0 *)arg0)->unkB6C4 = 0;
    ((struct func_0042EF90_arg0 *)arg0)->unkB6C0 = temp_v0;
}
