/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_0068DE30;
extern void func_005C31F8(int a0, int a1, int a2, int a3, Pmf m);

void MLoggerControl__get_display_accel(int a0, int a1, int a2, int a3) {
    func_005C31F8(a0, a1, a2, a3, D_0068DE30);
}
