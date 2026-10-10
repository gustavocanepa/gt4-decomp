struct D_00689DD8 {
    int f0;
    D_00689DD8(int a) __asm__("func_005778F8");
    virtual ~D_00689DD8();
};

struct D_00689E30 : D_00689DD8 {
    int f8;
    D_00689E30(int x, int y) __asm__("func_00577DF0");
    virtual ~D_00689E30();
};

D_00689E30::D_00689E30(int x, int y) : D_00689DD8(y) {
    f8 = x;
}
