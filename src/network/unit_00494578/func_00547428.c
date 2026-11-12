#include "types.h"

struct Blk { char b[0x40]; };
extern char D_0064C380[0x40];

s32 func_00547428(struct Blk *dst)
{
    if (dst != 0) {
        do {
            *dst = *(struct Blk *)D_0064C380;
        } while (0);
        return 0;
    }
    return -1;
}
