/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Inferred: appends to the scratchpad packet at s->cur (DMA cnt tag, VIF MSKPATH3/FLUSHA/DIRECT,
 * then a GIF A+D tag) a full GS drawing-environment setup: SCISSOR_1 (0x40), SCISSOR_2 (0x41) from
 * the third argument, FRAME_1 (0x4C) with the frame base pointer from the first, XYOFFSET_1/2,
 * ALPHA_1, PRMODECONT, CLAMP_2, TEX1_1/2, TEST_1/2, ZBUF_1/2, PABE, FBA_1/2 and RGBAQ. The second
 * argument is not read. Register names follow the GS register numbers in each quad's address word. */
#include "spr.h"
typedef unsigned int u32;
typedef unsigned long long u64;
struct Quad { u32 w0; u32 w4; u64 reg; };
#define SET64(dst, val, addr) do { Quad *q = (dst); u64 data = (val); u64 reg = (addr); *(u64 *)q = data; q->reg = reg; } while (0)
struct Spr { char p0[0x1F8]; char *cur; };
extern "C" void func_004A9ED8(int fbp, int unused, u64 scissor2) {
    Spr *s = (Spr *)spr_base();
    u32 *p = (u32 *)s->cur;
    p[0] = 0x10000014;
    p[1] = 0;
    p[2] = 0x06008000;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0x13000000;
    p[7] = 0x51000013;
    SET64((Quad *)(p + 8), 0x1000000000008012ULL, 0xE);
    SET64((Quad *)(p + 12), 0x0FFF00000FFF0000ULL, 0x40);
    SET64((Quad *)(p + 16), scissor2, 0x41);
    SET64((Quad *)(p + 20), (u64)(fbp & 0x1FF) | 0xFFFFFF00010000ULL, 0x4C);
    SET64((Quad *)(p + 24), 0x0000800000008000ULL, 0x18);
    SET64((Quad *)(p + 28), 0x3F8000000000ULL, 0x19);
    SET64((Quad *)(p + 32), 0x8000000068ULL, 0x42);
    SET64((Quad *)(p + 36), 1, 0x1A);
    SET64((Quad *)(p + 40), 0, 9);
    SET64((Quad *)(p + 44), 1, 0x14);
    SET64((Quad *)(p + 48), 1, 0x15);
    SET64((Quad *)(p + 52), 0x31002, 0x47);
    SET64((Quad *)(p + 56), 0x31002, 0x48);
    SET64((Quad *)(p + 60), 0x101000000ULL, 0x4E);
    SET64((Quad *)(p + 64), 0x101000000ULL, 0x4F);
    SET64((Quad *)(p + 68), 0, 0x49);
    SET64((Quad *)(p + 72), 0, 0x4A);
    SET64((Quad *)(p + 76), 0, 0x4B);
    Quad *last = (Quad *)(p + 80);
    char *end = (char *)(last + 1);
    SET64(last, 0x80000000ULL, 1);
    s->cur = end;
}
