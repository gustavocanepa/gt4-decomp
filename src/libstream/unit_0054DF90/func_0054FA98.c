#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern s32 D_0064C4AC;
extern s32 D_0064C4B4;

s32 func_0054D0F0();                            /* extern */
s32 func_0054FEC8(void *);                      /* extern */
s32 func_00563028();                            /* extern */
s32 func_00563420();                            /* extern */
s32 func_00564728(s32);                         /* extern */
s32 func_005ADBC0();                            /* extern */
s32 func_005ADBD0(s32);                         /* extern */
s32 func_005ADCC0(s32);                         /* extern */
s32 func_005ADCE0(s32);                         /* extern */

struct func_0054FA98_arg0 {
    char pad0[0x8];
    void *unk8;
    s32 unkC;
};
struct func_0054FA98_temp_s1 {
    char pad0[0x38];
    s32 unk38;
    char pad3C[0x4];
    s32 unk40;
};

void func_0054FA98(struct func_0054FA98_arg0 *arg0) {
    s32 temp_a0;
    struct func_0054FA98_temp_s1 *temp_s1;

    temp_s1 = arg0->unk8;
    func_00563028();
    func_0054D0F0();
    func_00564728(arg0->unkC);
    func_0054FEC8(temp_s1);
    func_005ADCC0(D_0064C4AC);
    func_00563420();
    func_00564728(arg0->unkC);
    func_00563028();
    func_0054D0F0();
    func_005ADCE0(temp_s1->unk38);
    temp_s1->unk40 = 0;
    func_005ADCC0(temp_s1->unk38);
    temp_a0 = D_0064C4B4;
    if (temp_a0 != -1) {
        func_005ADBD0(temp_a0);
    }
loop_2:
    func_005ADBC0();
    goto loop_2;
}
