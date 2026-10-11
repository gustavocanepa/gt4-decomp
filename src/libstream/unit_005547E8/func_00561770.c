/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct { char b[24]; } Block24;
void func_00561770(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x240);
    *(Block24 *)temp_v0 = *(Block24 *)((char *)arg0 + 0x70);
}
