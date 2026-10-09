/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0069A788;
extern void func_005E3E70(int a0, int a1, int a2, int a3, Pmf m);

void MBlinkActor__set_flick(int a0, int a1, int a2, int a3) {
    func_005E3E70(a0, a1, a2, a3, D_0069A788);
}
