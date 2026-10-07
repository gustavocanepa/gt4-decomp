extern "C" int D_00623A20;
extern "C" int D_00623A28;
extern "C" int D_00623A2C;

extern "C" void func_00460188(void);
extern "C" void func_00461AF8(void);

extern "C" void func_00461D78(void) {
    switch (D_00623A20) {
    case 1:
        func_00460188();
        break;
    case 2:
        func_00461AF8();
        break;
    }
    D_00623A20 = 0;
    D_00623A2C = -1;
    D_00623A28 = -1;
}
