/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00692DE8;
extern void func_005CE270(int a0, int a1, int a2, int a3, Pmf m);

void MSlideShowFace__doPlay(int a0, int a1, int a2, int a3) {
    func_005CE270(a0, a1, a2, a3, D_00692DE8);
}
