/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00693990;
extern void func_005CFB40(int a0, int a1, int a2, int a3, Pmf m);

void MGTShirt__clear(int a0, int a1, int a2, int a3) {
    func_005CFB40(a0, a1, a2, a3, D_00693990);
}
