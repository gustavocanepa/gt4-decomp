/* compiler: ee-gcc2.96-no-strict-aliasing */
struct D_00661688 {
    int f0;
    char pad4[0x48 - 4];
    short f48;
    short f4A;
    D_00661688() __asm__("func_001CBFE0");
    virtual ~D_00661688();
};

/* A standard-style allocator object: the default argument `Alloc()` of the vector constructor is
   a stack temporary passed by reference, which leaves an unused 16-byte slot in the frame. */
struct Alloc {
    Alloc() {}
    Alloc(const Alloc &) {}
};

struct Vector {
    Alloc a;
    int *start, *finish, *eos;
    Vector(const Alloc &al = Alloc()) : a(al), start(0), finish(0), eos(0) {}
};

struct D_006611F0 : D_00661688 {
    Vector items;
    int f60;
    D_006611F0() __asm__("func_005D1868");
    virtual ~D_006611F0();
};

D_006611F0::D_006611F0() : f60(0) {
}
