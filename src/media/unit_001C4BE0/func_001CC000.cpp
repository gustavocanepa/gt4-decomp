/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;

struct Block64 { long long q[8]; };

/* Named after its vtable so the compiler-made vptr store _vt$10D_00661688 resolves. */
struct D_00661688 {
    int m0;
    Block64 data;
    u16 m48;
    D_00661688(const D_00661688 &o);
    virtual ~D_00661688();
};

D_00661688::D_00661688(const D_00661688 &o) : m0(o.m0), data(o.data), m48(o.m48) {
}
