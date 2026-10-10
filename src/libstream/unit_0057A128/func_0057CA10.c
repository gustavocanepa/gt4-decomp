/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0057CA10_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_0057CA10(struct func_0057CA10_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}
