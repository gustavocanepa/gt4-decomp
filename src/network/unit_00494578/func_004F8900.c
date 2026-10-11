#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004F8900_arg0 {
    char pad0[0x184];
    void *unk184;
};

void func_004F8900(struct func_004F8900_arg0 *arg0, void *arg1) {
    func_004F8790(arg0);
    arg0->unk184 = arg1;
}
