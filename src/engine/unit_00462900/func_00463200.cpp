struct Slot {
    char data[0x24];
};

extern int D_00623A74;
extern Slot D_008485C0[3];

extern "C" void func_00575DA0(int h);
extern "C" void func_00462D10(int a);
extern "C" void func_00462960(Slot *s);
extern "C" void func_00462E88(void);
extern "C" void func_00462EA8(void);

extern "C" void func_00463200(void) {
    int *h = &D_00623A74;
    if (*h) {
        func_00575DA0(*h);
        *h = 0;
    }
    func_00462D10(1);
    func_00462960(&D_008485C0[0]);
    func_00462960(&D_008485C0[1]);
    func_00462960(&D_008485C0[2]);
    func_00462E88();
    func_00462EA8();
}
