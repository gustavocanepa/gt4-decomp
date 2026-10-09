/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0068DDF8;
extern void func_005C2E30(int a0, int a1, int a2, int a3, Pmf m);

void MLoggerControl__analyze_stop(int a0, int a1, int a2, int a3) {
    func_005C2E30(a0, a1, a2, a3, D_0068DDF8);
}
