/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_006939D8;
extern void func_005CFDC0(int a0, int a1, int a2, int a3, Pmf m);

void MGTShirt__get_threshold_pattern_base(int a0, int a1, int a2, int a3) {
    func_005CFDC0(a0, a1, a2, a3, D_006939D8);
}
