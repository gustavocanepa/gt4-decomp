/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_006937F0;
extern void func_005CF380(int a0, int a1, int a2, int a3, Pmf m);

void MEyetoyFace__get_device(int a0, int a1, int a2, int a3) {
    func_005CF380(a0, a1, a2, a3, D_006937F0);
}
