/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_006936B8;
extern void func_005CED88(int a0, int a1, int a2, int a3, Pmf m);

void MEyetoy__get_connected(int a0, int a1, int a2, int a3) {
    func_005CED88(a0, a1, a2, a3, D_006936B8);
}
