extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 free(...) throw();

struct func_0054F7A0_arg0 {
    char pad0[0x4];
    char *unk4;
    char *unk8;
    char *unkC;
};

void func_0054F7A0(char *arg0) {
    free(((struct func_0054F7A0_arg0 *)arg0)->unkC);
    free(((struct func_0054F7A0_arg0 *)arg0)->unk8);
    free(((struct func_0054F7A0_arg0 *)arg0)->unk4);
    free(arg0);
}

}
