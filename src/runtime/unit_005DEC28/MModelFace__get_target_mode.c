/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0069C3C0;
extern void func_005E8878(int a0, int a1, int a2, int a3, Pmf m);

void MModelFace__get_target_mode(int a0, int a1, int a2, int a3) {
    func_005E8878(a0, a1, a2, a3, D_0069C3C0);
}
