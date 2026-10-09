/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00693A10;
extern void func_005CFFA8(int a0, int a1, int a2, int a3, Pmf m);

void MGTShirt__set_focus(int a0, int a1, int a2, int a3) {
    func_005CFFA8(a0, a1, a2, a3, D_00693A10);
}
