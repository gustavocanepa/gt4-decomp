typedef int s32;

/* The base class, named after its constructor (func_005659D8) so that __13func_005659D8
   resolves. The vptr sits after its 0x68 bytes of data. */
struct func_005659D8 {
    char pad[0x18];
    s32 type;
    char pad2[0x4C];
    func_005659D8();
    virtual ~func_005659D8();
};

/* The class has no known name: it is named after its vtable (0x006898F8) so that
   _vt$10D_006898F8 resolves. A real C++ constructor: the compiler's own vptr store gives the
   original's scheduling; the same stores written by hand in C do not. */
struct D_006898F8 : func_005659D8 {
    D_006898F8();
    virtual ~D_006898F8();
};

extern D_006898F8 *D_008A1AF4;

D_006898F8::D_006898F8() {
    type = 2;
    D_008A1AF4 = this;
}
