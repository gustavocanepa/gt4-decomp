/* Named after their constructors so that the calls resolve. */
struct func_00574D78 {
    char data[0x30];
    func_00574D78();
};

struct D_00659F18;

struct func_001095E8 {
    char data[0x14];
    func_001095E8(D_00659F18 *owner, int arg, int flags);
};

/* The root class of func_00108F78.cpp; named after its vtable (0x00659F18). */
struct D_00659F18 {
    func_00574D78 m0;
    func_001095E8 m30;
    func_001095E8 m44;
    int m58;
    int m5C;
    int m60;
    virtual ~D_00659F18();
    D_00659F18(int a, int b);
};

D_00659F18::D_00659F18(int a, int b) : m30(this, a, 0), m44(this, b, 0) {
    m58 = 0;
    m5C = 0;
    m60 = 0;
}
