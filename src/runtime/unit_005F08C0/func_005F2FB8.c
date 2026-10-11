/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { char b[16]; } Block16;
void func_005F2FB8(void *arg0, s32 arg1, void *arg2) {
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != arg1) {
        do {
            *(Block16 *)var_a0 = *(Block16 *)arg2;
            var_a0 += 0x10;
        } while (var_a0 != arg1);
    }
}
