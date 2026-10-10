#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { s32 a; s32 b; s32 x; u8 pad[0x24]; } E;
s32 func_00433470(E *arg0) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 10; i++) {
        if (arg0[i].x != 0x157529FF) n++;
    }
    return n;
}
