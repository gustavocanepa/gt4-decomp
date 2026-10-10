/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0068DDF0;
extern void func_005C2E30(int a0, int a1, int a2, int a3, Pmf m);

void MLoggerControl__analyze_start(int a0, int a1, int a2, int a3) {
    func_005C2E30(a0, a1, a2, a3, D_0068DDF0);
}
