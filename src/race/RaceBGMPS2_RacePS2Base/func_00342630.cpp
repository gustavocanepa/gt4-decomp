#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001056A0(void *);                      /* extern */
s32 func_00105918(void *);                          /* extern */
s32 func_004A29A8(s32);                     /* extern */
s32 func_004A5418(s32);                     /* extern */
s32 func_004A5688();                            /* extern */
s32 func_004A6290(s32, s32, s32, s32);  /* extern */
s32 func_004AB040(s32);                     /* extern */

struct func_00342630_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_00342630(void *arg0) {
    s32 temp_s1;

    func_004A5418(2);
    func_001056A0(arg0);
    func_004AB040(5);
    func_004A29A8(0);
    temp_s1 = ((struct func_00342630_arg0 *)arg0)->unk18;
    func_004A6290(0, 0, temp_s1, func_00105918(arg0));
    func_004A5688();
}
