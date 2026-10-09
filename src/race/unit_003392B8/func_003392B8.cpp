extern char D_006201D0;
extern char D_006201D8;

extern "C" void func_00387B30(void *a0, void *a1);

extern "C" void func_003392B8(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00387B30(&D_006201D0, &D_006201D8);
    }
}

extern "C" void func_00330840(void) {
    func_003392B8(1, 0xFFFF);
}
