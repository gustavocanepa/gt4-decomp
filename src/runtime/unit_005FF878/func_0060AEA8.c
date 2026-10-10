/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { char b[16]; } Block16;
void func_0060AEA8(void *arg0, void *arg1) {
    *(Block16 *)((char *)arg0 + 0x64) = *(Block16 *)arg1;
}
