/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0068E5E8;
extern void func_005C4190(int a0, int a1, int a2, int a3, Pmf m);

void MQuickWork__set_IsASpec(int a0, int a1, int a2, int a3) {
    func_005C4190(a0, a1, a2, a3, D_0068E5E8);
}
