extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A1E10(...) throw();

extern char D_006A17F8[];
extern char D_006A1808[];
extern char D_006A1810[];
extern char D_006244D8[];
struct func_003AD458_arg0 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

void func_003AD458(char *arg0) {
    s32 var_a0;
    s32 temp_v1;

    if (((struct func_003AD458_arg0 *)arg0)->unk18 == 0) {
        temp_v1 = *(s32 *)D_006244D8;
        var_a0 = 0;
        switch (temp_v1) {                          /* irregular */
        case 0:
            var_a0 = (s32)D_006A17F8;
            break;
        case 1:
            var_a0 = (s32)D_006A1808;
            break;
        }
        ((struct func_003AD458_arg0 *)arg0)->unk18 = func_003A1E10(var_a0);
        ((struct func_003AD458_arg0 *)arg0)->unk1C = func_003A1E10((s32)D_006A1810);
    }
}

}
