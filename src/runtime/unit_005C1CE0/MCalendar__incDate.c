/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0068EC98;
extern void func_005C4DB8(int a0, int a1, int a2, int a3, Pmf m);

void MCalendar__incDate(int a0, int a1, int a2, int a3) {
    func_005C4DB8(a0, a1, a2, a3, D_0068EC98);
}
