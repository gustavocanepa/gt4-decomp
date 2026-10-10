struct D_00659AC0 {
    char pad0[0x64];
    virtual ~D_00659AC0() __asm__("func_00101078");
};

struct CarIconMaker : D_00659AC0 {
    char pad68[0x80 - 0x68];
    CarIconMaker(int id, void *owner, void *src) __asm__("func_00393A48");
    ~CarIconMaker() {}
    void make() __asm__("func_00393AB0");
};

struct Src {
    char pad0[0x60];
    int *ids;
};

extern "C" void CarIconMaker__structor_1(void *owner, Src *src) {
    CarIconMaker maker(*src->ids, owner, src);
    maker.make();
}
