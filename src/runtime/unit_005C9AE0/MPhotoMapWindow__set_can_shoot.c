/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00692360;
extern void func_005CD4F0(int a0, int a1, int a2, int a3, Pmf m);

void MPhotoMapWindow__set_can_shoot(int a0, int a1, int a2, int a3) {
    func_005CD4F0(a0, a1, a2, a3, D_00692360);
}
