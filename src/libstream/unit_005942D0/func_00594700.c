/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_00594700.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00594700_arg0_unk50 {
    char pad0[0x14];
    s32 (*unk14)();
};
struct func_00594700_arg0 {
    char pad0[0x50];
    struct func_00594700_arg0_unk50 *unk50;
};

void func_00594700(struct func_00594700_arg0 *arg0) {
    arg0->unk50->unk14();
}
