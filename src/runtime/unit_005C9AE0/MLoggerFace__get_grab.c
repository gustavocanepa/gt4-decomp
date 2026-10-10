/* compiler: ee-gcc2.96-nsa-nosib-as2004 */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00693AE0;
extern void func_005D05A0(int a0, int a1, int a2, int a3, Pmf m);

void MLoggerFace__get_grab(int a0, int a1, int a2, int a3) {
    func_005D05A0(a0, a1, a2, a3, D_00693AE0);
}
