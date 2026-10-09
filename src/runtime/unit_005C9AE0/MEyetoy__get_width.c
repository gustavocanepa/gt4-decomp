/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_006936C8;
extern void func_005CEE88(int a0, int a1, int a2, int a3, Pmf m);

void MEyetoy__get_width(int a0, int a1, int a2, int a3) {
    func_005CEE88(a0, a1, a2, a3, D_006936C8);
}
