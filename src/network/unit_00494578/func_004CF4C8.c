#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004CF4C8_arg0 {
    char pad0[0x7C];
    void *unk7C;
};

void func_004CF4C8(struct func_004CF4C8_arg0 *arg0, void *arg1) {
    arg0->unk7C = (void *) ((arg1 != NULL) ? arg1 : arg0);
}
