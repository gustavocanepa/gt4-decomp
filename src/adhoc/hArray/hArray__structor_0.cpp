/* compiler: ee-gcc2.96-no-strict-aliasing */
struct D_00661688 {
    int f0;
    D_00661688() __asm__("func_0030A678");
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

struct hArray__vtable : D_00661688 {
    int pad8[2];
    Vector items;
    int f60;
    hArray__vtable() __asm__("func_002EF6A0");
    virtual ~hArray__vtable();
};

hArray__vtable::hArray__vtable() : f60(0) {
}
