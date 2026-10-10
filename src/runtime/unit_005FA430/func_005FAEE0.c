/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { char b[32]; } Block32;
void func_005FAEE0(void *arg0, void *arg1) {
    *(Block32 *)((char *)arg0 + 0x3468) = *(Block32 *)arg1;
}
