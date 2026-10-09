/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0069C848;
extern void func_005E9A90(int a0, int a1, int a2, int a3, Pmf m);

void MProgressFace__get_raw_mode(int a0, int a1, int a2, int a3) {
    func_005E9A90(a0, a1, a2, a3, D_0069C848);
}
