extern "C" void *func_0043A3F8(void *self);
extern "C" void func_00444190(void *self);
extern "C" void *func_00343490(void *self);
extern "C" char D_00688280[];

extern "C" void *func_0043DC98(void *arg0) {
    func_0043A3F8(arg0);
    *(void **)arg0 = D_00688280;

    char *p = (char *)arg0 + 8;
    for (int i = 2; i != -1; i--) {
        func_00444190(p);
        p += 0x178;
    }

    return func_00343490((char *)arg0 + 0x4A0);
}
