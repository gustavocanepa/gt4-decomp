/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Packs a position tag, builds a packet in 0x60 bytes of scratchpad (func_004A4CA8) and closes it
   with two GIF qwords in 0x20 more, recording the size and both DMA addresses. The empty loops
   keep sched2 from mixing the qword stores with their neighbours, as in retail. */
#include "spr.h"
struct Spr { char pad[0x1fc]; int cursor; };
extern "C" int func_004A4CA8(char *, void *, int, int, int, int);
extern unsigned int D_00624C64, D_00624C68, D_00624C6C;
static inline char *allocate(Spr *spr, int amount) {
    int value = spr->cursor - amount - 16;
    spr->cursor = value;
    return (char *)value;
}
extern "C" void func_00499B60(int x, int y, int z, int a, int b, int c, int d) {
    Spr *spr = (Spr *)spr_base();
    unsigned int tag = ((x >> 6) & 0xFFFF) | (((z >> 6) & 0xFF) << 16) | (y << 24);
    char *buf = allocate(spr, 0x50);
    int n = func_004A4CA8(buf, &tag, a, b, c, d);
    D_00624C6C = n;
    D_00624C64 = (unsigned int)buf & 0x0FFFFFFF;
    char *p = allocate(spr, 0x10);
    do { } while (0);
    *(unsigned long long *)p = 0x1000000000008001ULL;
    *(unsigned long long *)(p + 8) = 0xE;
    do { } while (0);
    p += 16;
    *(unsigned long long *)p = 0;
    *(unsigned long long *)(p + 8) = 0x3F;
    do { } while (0);
    D_00624C68 = (unsigned int)(p - 16) & 0x0FFFFFFF;
}
