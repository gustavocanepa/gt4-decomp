/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_006936E8;
extern void func_005CF158(int a0, int a1, int a2, int a3, Pmf m);

void func_005CE9A8(int a0, int a1, int a2, int a3) {
    func_005CF158(a0, a1, a2, a3, D_006936E8);
}
