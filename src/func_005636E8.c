/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
} State_005636E8;

extern State_005636E8 D_00874378;

int func_00563408(int n);

void func_005636E8(int arg) {
    D_00874378.m8 = func_00563408(3);
    D_00874378.mC = func_00563408(4);
    D_00874378.m10 = func_00563408(5);
    D_00874378.m4 = arg;
    D_00874378.m0 = 1;
}
