extern char D_00621C18;
extern char D_00621C20;

extern "C" void func_00387B30(void *a0, void *a1);

extern "C" void func_003C8EA0(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 == 1)) {
        func_00387B30(&D_00621C18, &D_00621C20);
    }
}

extern "C" void func_00330840(void) {
    func_003C8EA0(1, 0xFFFF);
}
