/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Reserves a DMA packet header below c->top (32 more bytes with mode bit 0x20000, for an EOP
   A+D GIF tag), patches the previous mark with its address and returns it. The tag stores sit in a
   do { } while (0) packet macro (sched1 barrier) and 'p -= 4' is its own statement, or the
   -0x10 / -0x20 adjustments fold into one -0x30. */
typedef unsigned int u32;
typedef unsigned long u64;

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | \
     ((u64)(flg) << 58) | ((u64)(nreg) << 60))

struct Ctx {
    char pad[0x1FC];
    u32 *top;
    int x200;
    int x204;
    u32 *mark;
};

extern "C" u32 *func_004A1FA8(Ctx *c, u32 mode) {
    u32 flag = mode & 0x20000;
    u32 *p = c->top;
    p -= 4;
    if (flag) p -= 8;
    c->top = p;
    *c->mark = (u32)p & 0x0FFFFFFF;
    if (flag) {
        p[0] = 0x10000001;
        do {
            u64 *q = (u64 *)(p + 4);
            q[0] = SCE_GIF_SET_TAG(0, 1, 0, 0, 0, 1);
            q[1] = 0xE;
        } while (0);
        p += 8;
    }
    p[0] = mode ? (mode | 0xA0000000) : 0x20000000;
    p[2] = 0;
    c->mark = p + 1;
    return p;
}
