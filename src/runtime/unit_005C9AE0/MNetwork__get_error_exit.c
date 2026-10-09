/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00696EC8;
extern void func_005D3A60(int a0, int a1, int a2, int a3, Pmf m);

void MNetwork__get_error_exit(int a0, int a1, int a2, int a3) {
    func_005D3A60(a0, a1, a2, a3, D_00696EC8);
}
