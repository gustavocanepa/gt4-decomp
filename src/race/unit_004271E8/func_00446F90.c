#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004470B8();                            /* extern */
s32 func_004470C0(void *);                      /* extern */

extern char D_006882D8[];
struct func_00446F90_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

void func_00446F90(struct func_00446F90_arg0 *arg0) {
    arg0->unkAC = (s32)D_006882D8;
    func_004470B8();
    func_004470C0(arg0);
}
