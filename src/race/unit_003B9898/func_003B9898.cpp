extern char D_00621A18;
extern char D_00621A20;

extern "C" void func_00387B30(void *a0, void *a1);

extern "C" void func_003B9898(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00387B30(&D_00621A18, &D_00621A20);
    }
}

extern "C" void func_00330840(void) {
    func_003B9898(1, 0xFFFF);
}
