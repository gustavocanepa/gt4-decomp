#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00476870(void *);                      /* extern */
s32 func_004768C0();                            /* extern */

struct func_00476790_arg1 {
    s32 unk0;
    s32 unk4;
};
struct func_00476790_arg0 {
    s32 unk0;
    s32 unk4;
};

void *func_00476790(struct func_00476790_arg0 *arg0, struct func_00476790_arg1 *arg1) {
    s32 temp_s1;

    temp_s1 = arg1->unk0;
    func_004768C0();
    arg0->unk0 = temp_s1;
    arg0->unk4 = (s32) arg1->unk4;
    func_00476870(arg0);
    return arg0;
}
