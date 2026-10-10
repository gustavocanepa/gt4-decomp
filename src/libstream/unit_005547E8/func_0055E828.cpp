struct Sys {
    int handle;
    char pad4[0x3F8 - 4];
    int ready;
};

extern "C" Sys D_008735C0;
extern "C" char D_00873DC0[];
extern "C" void func_00578500(int handle);
extern "C" void func_00578168(Sys *s, int kind, int a, void *buf, int size);

extern "C" void func_0055E828(void) {
    Sys *s = &D_008735C0;
    func_00578500(s->handle);
    s->ready = 1;
    func_00578168(s, 3, 0, D_00873DC0, 0x80);
}
