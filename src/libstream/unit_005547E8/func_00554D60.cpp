/* compiler: ee-gcc2.96-as2004 */
struct Hdr {
    int m0;
    int size;
} __attribute__((packed));
struct Ring {
    int m0;
    char m4[0x24 - 4];
    int mask;
    int m28;
    int wp;
    int used;
    int func_00575DA0;
};
extern "C" int func_005B72A8(void);
extern "C" void func_005B72F8(void);
extern "C" void func_00554910(Ring *r, void *p);

extern "C" void func_00554D60(Ring *r, Hdr *h)
{
    func_005B72A8();
    int n = h->size + 16;
    r->wp = (r->wp + n) & r->mask;
    r->func_00575DA0 -= n;
    r->used += n;
    func_005B72F8();
    func_00554910(r, r->m4);
}
