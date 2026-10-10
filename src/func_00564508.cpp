extern "C" int D_00654D70;
extern "C" int D_00654D74;
extern "C" int D_00654D78;
extern "C" int D_00654D7C;
extern "C" int D_00654DA0;

extern "C" void func_00564508(void) {
    if (D_00654DA0 == 3) {
        D_00654D7C = D_00654D78;
    } else {
        int t = D_00654D74;
        D_00654D74 = D_00654D70;
        D_00654D70 = t;
        D_00654D7C = t;
    }
}
