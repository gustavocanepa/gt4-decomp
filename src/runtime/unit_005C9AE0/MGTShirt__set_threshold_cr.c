/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_006939B0;
extern void func_005CFCD8(int a0, int a1, int a2, int a3, Pmf m);

void MGTShirt__set_threshold_cr(int a0, int a1, int a2, int a3) {
    func_005CFCD8(a0, a1, a2, a3, D_006939B0);
}
