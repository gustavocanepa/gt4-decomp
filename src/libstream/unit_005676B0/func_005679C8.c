extern int func_00567EC0(int);
extern void func_005A48D8(int, int, int);
void func_005679C8(int *s) {
    int p = func_00567EC0(0x500);
    s[6] = 0x500;
    s[0] = p;
    func_005A48D8(p, 0, 0x500);
    s[1] = 0;
    s[5] = 0;
    s[2] = 0;
    s[3] = 0;
    s[4] = 1;
}
