#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0057B130(s32);                             /* extern */

struct func_0057B168_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_0057B168(struct func_0057B168_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = func_0057B130(arg1);
}
