/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_006937F8;
extern void func_005CF478(int a0, int a1, int a2, int a3, Pmf m);

void MEyetoyFace__set_processor(int a0, int a1, int a2, int a3) {
    func_005CF478(a0, a1, a2, a3, D_006937F8);
}
