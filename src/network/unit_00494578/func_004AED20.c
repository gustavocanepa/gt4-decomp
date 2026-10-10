/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00576788();                            /* extern */
s32 func_005767C0(void *);                      /* extern */
s32 func_0057CB00(s32, void *);                 /* extern */

struct func_004AED20_arg1 {
    char pad0[0x50];
    void *unk50;
};
struct func_004AED20_arg0 {
    char pad0[0x80];
    s32 unk80;
};

void func_004AED20(void *arg0, void *arg1) {
    func_00576788();
    ((struct func_004AED20_arg1 *)arg1)->unk50 = arg0;
    func_0057CB00(arg0 + 0xAC, arg1 + 0x54);
    ((struct func_004AED20_arg0 *)arg0)->unk80 = 0;
    func_005767C0(arg0);
}
