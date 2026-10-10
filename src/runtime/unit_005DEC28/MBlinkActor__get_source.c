/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0069A770;
extern void func_005E3D70(int a0, int a1, int a2, int a3, Pmf m);

void MBlinkActor__get_source(int a0, int a1, int a2, int a3) {
    func_005E3D70(a0, a1, a2, a3, D_0069A770);
}
