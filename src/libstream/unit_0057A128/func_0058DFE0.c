/* compiler: ee-gcc2.9-991111 */
extern int *D_0087E4A8;
extern int *D_0087E4AC;
extern int *D_0087E4B0;
extern int D_00657AF8;

void func_005ADCD0(int a);

void func_0058DFE0(unsigned int addr) {
    int *p = (int *)(addr | 0x20000000);
    if (D_0087E4A8 != 0) {
        *D_0087E4A8 = p[0];
    }
    if (D_0087E4AC != 0) {
        *D_0087E4AC = p[1];
    }
    if (D_0087E4B0 != 0) {
        *D_0087E4B0 = p[36];
    }
    func_005ADCD0(D_00657AF8);
}
