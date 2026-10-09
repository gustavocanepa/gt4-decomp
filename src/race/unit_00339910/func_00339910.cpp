extern char D_006201E8;
extern char D_006201F0;

extern "C" void func_00387B30(void *a0, void *a1);

extern "C" void func_00339910(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00387B30(&D_006201E8, &D_006201F0);
    }
}

extern "C" void func_00330840(void) {
    func_00339910(1, 0xFFFF);
}
