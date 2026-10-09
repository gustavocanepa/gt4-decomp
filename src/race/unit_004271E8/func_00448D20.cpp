extern char D_00846390;
extern char D_006A6FE0;

extern "C" void func_0057B168(void *a0, void *a1);

extern "C" void func_00448D20(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_0057B168(&D_00846390, &D_006A6FE0);
    }
}

extern "C" void func_00330840(void) {
    func_00448D20(1, 0xFFFF);
}
