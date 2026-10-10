/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { char b[16]; } Block16;
struct func_005CBE38_arg0 {
    char pad0[0x10];
    void *unk10;
};

void func_005CBE38(struct func_005CBE38_arg0 *arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = arg0->unk10;
    *(Block16 *)((char *)temp_v0 + 0x1194) = *(Block16 *)arg1;
}
