/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Opens an A+D GIF tag qword (nreg 1, register list 0xE) after the current one. The tag stores
   sit in a do { } while (0) block (a packet macro): its loop notes stop sched1 from hoisting the
   two constants above the Packet bookkeeping stores. */
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | \
     ((u64)(flg) << 58) | ((u64)(nreg) << 60))
#define SCE_GIF_PACKED_AD 0xE

struct Packet {
    int f0;
    u128 *ptr;
    int count;
    int fC;
    int total;
};

extern "C" void func_004A9020(Packet *p) {
    u64 *tag = (u64 *)(p->ptr + p->count);
    p->count = 1;
    p->total++;
    p->ptr = (u128 *)tag;
    do {
        tag[0] = SCE_GIF_SET_TAG(0, 0, 0, 0, 0, 1);
        tag[1] = SCE_GIF_PACKED_AD;
    } while (0);
}
