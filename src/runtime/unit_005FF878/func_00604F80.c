/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { char b[24]; } Block24;
void func_00604F80(void *arg0, void *arg1) {
    *(Block24 *)((char *)arg0 + 0x8c4) = *(Block24 *)arg1;
}
