extern unsigned char D_006220F4;
extern unsigned char D_006220F5;
extern float D_006220F8;
extern float D_006220FC;
extern unsigned char D_00622100;
extern unsigned char D_00622101;
extern float D_00622104;
extern float D_00622108;
extern unsigned char D_0062210C;

void func_003F2070(void)
{
    if (D_0062210C == 0) {
        D_006220F8 = D_006220F4 * 0.01f;
        D_006220FC = D_006220F5 * 0.01f;
        D_00622104 = D_00622100 * 0.01f;
        D_00622108 = D_00622101 * 0.01f;
        D_0062210C = 1;
    }
}
