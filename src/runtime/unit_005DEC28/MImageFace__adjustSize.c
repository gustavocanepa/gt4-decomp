/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0069B820;
extern void func_005E62D0(int a0, int a1, int a2, int a3, Pmf m);

void MImageFace__adjustSize(int a0, int a1, int a2, int a3) {
    func_005E62D0(a0, a1, a2, a3, D_0069B820);
}
