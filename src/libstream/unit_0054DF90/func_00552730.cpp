typedef int s32;

/* The base class; its constructor is func_005659D8. Its vptr sits at 0x68. */
struct func_005659D8 {
    char pad[0x18];
    s32 m18;
    char pad2[0x4C];
    func_005659D8();
    virtual ~func_005659D8();
};

struct D_006898D8;
extern D_006898D8 *D_008A1B04;

/* Named after its vtable (no known class name) so the compiler-made vptr store
   _vt$10D_006898D8 resolves; a singleton constructor that registers itself in D_008A1B04. */
struct D_006898D8 : func_005659D8 {
    D_006898D8();
    virtual ~D_006898D8();
};

D_006898D8::D_006898D8() {
    m18 = 1;
    D_008A1B04 = this;
}
