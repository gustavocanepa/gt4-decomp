/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Opens a REGLIST GIF tag qword (flg 1) with nreg registers listed in regs after the current one.
   The tag stores sit in a do { } while (0) block (a packet macro) so sched1 keeps the tag after
   the Packet bookkeeping; nloop must be int for the or's register order. */
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | \
     ((u64)(flg) << 58) | ((u64)(nreg) << 60))

struct Packet {
    int f0;
    u128 *ptr;
    int count;
    int fC;
    int total;
};

extern "C" void func_004A90A8(Packet *p, int nreg, u64 regs, int nloop) {
    u64 *tag = (u64 *)(p->ptr + p->count);
    p->count = 1;
    p->total++;
    p->ptr = (u128 *)tag;
    do {
        tag[0] = SCE_GIF_SET_TAG(nloop, 0, 0, 0, 1, nreg);
        tag[1] = regs;
    } while (0);
}
