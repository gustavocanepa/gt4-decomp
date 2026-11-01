/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Appends one data qword (lo, hi) to the open GIF tag, then rewrites the tag's NLOOP (low 15
   bits) to count - 1 and returns total - 1. The qword stores sit in a do { } while (0) block (a
   packet macro); without it sched1 hoists the -0x8000 mask to the top. */
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Packet {
    int f0;
    u128 *ptr;
    int count;
    int fC;
    int total;
};

extern "C" int func_004A9108(Packet *p, u64 hi, u64 lo) {
    do {
        u64 *q = (u64 *)(p->ptr + p->count);
        q[1] = hi;
        q[0] = lo;
    } while (0);
    p->count++;
    p->total++;
    *(int *)p->ptr = *(int *)p->ptr & -0x8000;
    *(int *)p->ptr = *(int *)p->ptr + p->count - 1;
    return p->total - 1;
}
