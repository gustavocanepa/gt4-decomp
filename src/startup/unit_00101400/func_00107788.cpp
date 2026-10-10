struct Elem {
    char data[0x3C];
};

struct Pages {
    Elem elems[2];
    int cur;
    Elem *current() { return &elems[cur]; }
};

struct Screen {
    char pad[0x3C];
    Pages pages;
};

extern Screen D_006184D0;

extern "C" void func_004A22C0(int a);
extern "C" void func_001060F8(Screen *s, int a, int b, int c);
extern "C" void func_00106258(Screen *s, int a, int b);
extern "C" void func_00105608(Elem *e);

extern "C" void func_00107788(void) {
    func_004A22C0(1);
    func_001060F8(&D_006184D0, 1, 2, 1);
    func_00106258(&D_006184D0, 0, 0);
    func_00105608(D_006184D0.pages.current());
}
