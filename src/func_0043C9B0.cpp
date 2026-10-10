typedef int s32;

/* The base class, named after its constructor so that __13func_0043C310 resolves. */
struct func_0043C310 {
    char pad0[0xC];
    func_0043C310(const char *name, const char *type, const char *extra);
    virtual ~func_0043C310();
    void func_0043B9D8(s32 n);
};

extern char D_00623450[];
extern char D_006234A0[];

/* No known name: named after its vtable (0x00688050) so that _vt$10D_00688050 resolves. */
struct D_00688050 : func_0043C310 {
    char pad10[0x16];
    char m26;
    char m27;
    char m28;
    D_00688050();
    virtual ~D_00688050();
};

D_00688050::D_00688050() : func_0043C310(0, D_00623450, D_006234A0) {
    func_0043B9D8(0);
    m26 = 1;
    m27 = 1;
    m28 = 1;
}
