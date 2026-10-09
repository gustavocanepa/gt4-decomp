extern char D_00621A30;
extern char D_00621A38;

extern "C" void func_00387B30(void *a0, void *a1);

extern "C" void func_003BAB30(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00387B30(&D_00621A30, &D_00621A38);
    }
}

extern "C" void func_00330840(void) {
    func_003BAB30(1, 0xFFFF);
}
