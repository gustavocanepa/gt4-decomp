/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00693800;
extern void func_005CF528(int a0, int a1, int a2, int a3, Pmf m);

void func_005CF358(int a0, int a1, int a2, int a3) {
    func_005CF528(a0, a1, a2, a3, D_00693800);
}
