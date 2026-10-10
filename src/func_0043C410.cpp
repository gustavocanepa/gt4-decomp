typedef int s32;

/* The base class, named after its constructor so that __13func_0043C310 resolves. */
struct func_0043C310 {
    char pad0[8];
    s32 m8;
    func_0043C310(const char *name, const char *type, s32 n);
    virtual ~func_0043C310();
    void func_0043B8D8(s32 n);
};

extern char D_006233E8[];

/* No known name: named after its vtable (0x00688130) so that _vt$10D_00688130 resolves. */
struct D_00688130 : func_0043C310 {
    char pad10[0xA];
    char m1A;
    D_00688130();
    virtual ~D_00688130();
};

D_00688130::D_00688130() : func_0043C310(0, D_006233E8, m8) {
    func_0043B8D8(0);
    m1A = 1;
}
