/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_006936B0;
extern void func_005CECF0(int a0, int a1, int a2, int a3, Pmf m);

void MEyetoy__update_camera(int a0, int a1, int a2, int a3) {
    func_005CECF0(a0, a1, a2, a3, D_006936B0);
}
