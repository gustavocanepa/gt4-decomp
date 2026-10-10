#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0047BA10(void *);                      /* extern */
s32 func_00484A70(s32);                         /* extern */

struct func_00477D98_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00477D98(void *arg0) {
    s32 temp_v1;

    temp_v1 = ((struct func_00477D98_arg0 *)arg0)->unk0;
    switch (temp_v1) {                              /* irregular */
    case 7:
        func_00484A70(((struct func_00477D98_arg0 *)arg0)->unk4);
        return;
    case 10:
        func_0047BA10(arg0 + 4);
        return;
    }
}
