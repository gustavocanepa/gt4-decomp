/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0069C850;
extern void func_005E9B90(int a0, int a1, int a2, int a3, Pmf m);

void MProgressFace__set_raw_mode(int a0, int a1, int a2, int a3) {
    func_005E9B90(a0, a1, a2, a3, D_0069C850);
}
