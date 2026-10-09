/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00698010;
extern void func_005DA658(int a0, int a1, int a2, int a3, Pmf m);

void MMovieFace__set_interlace(int a0, int a1, int a2, int a3) {
    func_005DA658(a0, a1, a2, a3, D_00698010);
}
