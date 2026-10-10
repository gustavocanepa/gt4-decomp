typedef int s32;

/* The base class; its constructor is func_00578048. Its vptr sits at 0x38. */
struct func_00578048 {
    char pad[0x2C];
    char *buf;
    s32 size;
    s32 m34;
    func_00578048();
    virtual ~func_00578048();
};

extern "C" s32 func_005782E8(s32 a, s32 b, s32 c);

/* Named after its vtable so the compiler-made vptr store _vt$10D_006897F8 resolves. */
struct D_006897F8 : func_00578048 {
    s32 m3C;
    s32 handle;
    char pad44[0x3C];
    char data[0x40];
    D_006897F8();
    virtual ~D_006897F8();
};

D_006897F8::D_006897F8() {
    buf = data;
    size = 0x40;
    m3C = 0;
    handle = func_005782E8(0, 0xFF, size);
}
