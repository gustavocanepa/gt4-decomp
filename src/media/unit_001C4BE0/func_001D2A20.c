#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_001D2610(void *, s32);                 /* extern */
s32 func_001D26D8();                            /* extern */
s32 func_001D26F8(void *);                      /* extern */
s32 func_001D2968(void *);                      /* extern */

struct func_001D2A20_arg0 {
    char pad0[0x698];
    s32 unk698;
    char pad69C[0x44];
    s32 unk6E0;
};

void func_001D2A20(struct func_001D2A20_arg0 *arg0) {
    s32 temp_s1;

    temp_s1 = arg0->unk698;
    if (arg0->unk6E0 != 0) {
        func_001D26D8();
        func_001D26F8(arg0);
    }
    func_001D2968(arg0);
    if (arg0->unk6E0 != 0) {
        if (temp_s1 != 5) {
            func_001D2610(arg0, temp_s1);
            return;
        }
        func_001D2610(arg0, 0);
    }
}
