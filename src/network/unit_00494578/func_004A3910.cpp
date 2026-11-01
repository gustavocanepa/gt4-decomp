/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Emits the XYOFFSET_1 (0x18) packet: DMA/VIF header, an EOP A+D GIF tag and the offset (x + 8,
   y + 8), then marks the register dirty (bit 2 of c->dirty). The tag stores and the dirty update
   sit in do { } while (0) packet macros: as sched1 barriers they keep the constants after the
   header and offset stores. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned long u64;

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | \
     ((u64)(flg) << 58) | ((u64)(nreg) << 60))

struct Ctx {
    char pad[0x1D8];
    u64 dirty;
    char pad1E0[0x18];
    u32 *cur;
    char pad1FC[0x70];
    u16 x;
    u16 y;
};

extern "C" void func_004A3910(Ctx *c) {
    u32 *p = c->cur;
    u64 *q = (u64 *)(p + 4);
    u32 x = c->x + 8;
    u32 y = c->y + 8;
    p[0] = 0x10000002;
    p[2] = 0x11000000;
    p[3] = 0x50000002;
    p[1] = 0;
    c->cur += 12;
    do {
        q[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 1);
        q[1] = 0xE;
    } while (0);
    p += 8;
    p[0] = x;
    p[1] = y;
    ((u64 *)p)[1] = 0x18;
    do {
        c->dirty |= 2;
    } while (0);
}
