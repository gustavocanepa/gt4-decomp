/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Packet {
    int f0;
    u128 *ptr;
    int count;
    int fC;
    int total;
};

extern "C" void func_004A9060(Packet *p, int prim) {
    u64 *tag = (u64 *)(p->ptr + p->count);
    p->count = 1;
    p->total++;
    p->ptr = (u128 *)tag;
    tag[0] = ((u64)prim << 47) | ((u64)1 << 46) | ((u64)1 << 60);
    tag[1] = 0xFFFFFFFFFFFFFFFEUL;
}
