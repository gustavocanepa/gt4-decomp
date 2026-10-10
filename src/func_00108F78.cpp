/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

/* The root class (its constructor is func_00109658); the vptr sits after its 0x64 bytes. */
struct func_00109658 {
    char pad0[0x64];
    virtual ~func_00109658();
};

/* The base class, named after its constructor so that __13func_00101030 resolves. */
struct func_00101030 : func_00109658 {
    s32 m68;
    func_00101030();
    virtual ~func_00101030();
};

/* No known name: named after its vtable (0x00659E80) so that _vt$10D_00659E80 resolves. */
struct D_00659E80 : func_00101030 {
    s32 *m6C;
    D_00659E80(s32 *args);
    virtual ~D_00659E80();
    void func_00109048(s32 a, f32 t);
};

extern "C" D_00659E80 *D_006186F8;

D_00659E80::D_00659E80(s32 *args) : m6C(args) {
    func_00109048(*args, 3.0f);
    m6C++;
    D_006186F8 = this;
}
