/* compiler: ee-gcc2.96-nsa-nosib-rf */

typedef struct { short delta; short index; int pfn; } Pmf;

extern Pmf D_00692358;
extern void func_005CD3F0(int a0, int a1, int a2, int a3, Pmf m);

void MPhotoMapWindow__get_can_shoot(int a0, int a1, int a2, int a3) {
    func_005CD3F0(a0, a1, a2, a3, D_00692358);
}
