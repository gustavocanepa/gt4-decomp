#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_004A5348(s32);                     /* extern */
s32 func_004A6100(f32, f32, f32, f32);          /* extern */
s32 func_004A74B4(s32);                         /* extern */

struct func_003D6930_arg0 {
    char pad0[0x44];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
};

void func_003D6930(char *arg0) {
    func_004A5348(2);
    func_004A74B4((s32)(arg0 + 4));
    func_004A5348(0);
    func_004A6100(((struct func_003D6930_arg0 *)arg0)->unk44, ((struct func_003D6930_arg0 *)arg0)->unk48, ((struct func_003D6930_arg0 *)arg0)->unk4C, ((struct func_003D6930_arg0 *)arg0)->unk50);
}

}
