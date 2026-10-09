/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00696ED0;
extern void func_005D3B60(int a0, int a1, int a2, int a3, Pmf m);

void func_005D33E0(int a0, int a1, int a2, int a3) {
    func_005D3B60(a0, a1, a2, a3, D_00696ED0);
}
