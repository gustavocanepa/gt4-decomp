/* compiler: ee-gcc2.96-no-strict-aliasing */
struct D_00689D90 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    D_00689D90(int a, int b, int c) __asm__("func_00575AE0");
    virtual ~D_00689D90();
    virtual void reset();
};

struct D_00689138 : D_00689D90 {
    D_00689138(int a, int b, int c) __asm__("func_0060B450");
    virtual ~D_00689138();
    virtual void reset();
};

D_00689138::D_00689138(int a, int b, int c) : D_00689D90(a, b, c) {
    D_00689D90 *base = this;
    base->reset();
}
