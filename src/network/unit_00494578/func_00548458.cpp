typedef int s32;

/* The base class, named after its constructor (func_00578048) so that __13func_00578048
   resolves. The vptr sits after its 0x38 bytes of data. */
struct func_00578048 {
    char pad[0x2C];
    char *buf;
    s32 size;
    s32 m34;
    func_00578048();
    virtual ~func_00578048();
};

/* No known name: named after its vtable (0x006897D8) so that _vt$10D_006897D8 resolves. */
struct D_006897D8 : func_00578048 {
    s32 m3C;
    char data[0x40];
    D_006897D8();
    virtual ~D_006897D8();
};

D_006897D8::D_006897D8() {
    buf = data;
    size = 0x40;
}
