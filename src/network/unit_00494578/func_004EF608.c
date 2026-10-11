#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0056FA90(void *);                      /* extern */
s32 func_0056FB50(void *, s32);                 /* extern */
s32 free(s32);                         /* extern */

struct func_004EF608_arg0 {
    s32 unk0;
    char pad4[0x78];
    s32 unk7C;
    s32 unk80;
};

void func_004EF608(void *arg0) {
    void *temp_s1;

    temp_s1 = arg0 + 4;
    if (((struct func_004EF608_arg0 *)arg0)->unk0 != 0) {
        ((struct func_004EF608_arg0 *)arg0)->unk0 = 0;
        func_0056FB50(temp_s1, ((struct func_004EF608_arg0 *)arg0)->unk7C);
        func_0056FA90(arg0 + 0x40);
        func_0056FA90(temp_s1);
        free(((struct func_004EF608_arg0 *)arg0)->unk7C);
        free(((struct func_004EF608_arg0 *)arg0)->unk80);
        ((struct func_004EF608_arg0 *)arg0)->unk7C = 0;
        ((struct func_004EF608_arg0 *)arg0)->unk80 = 0;
    }
}
