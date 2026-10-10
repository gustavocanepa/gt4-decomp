typedef int s32;

/* The base class; its constructor is func_00578048 (named after it so __13func_00578048
   resolves). Its vptr sits at 0x38. */
struct func_00578048 {
    char pad[0x2C];
    char *buf;
    s32 cap;
    s32 m34;
    func_00578048();
    virtual ~func_00578048();
};

/* The class is named after its vtable (no known name), so the compiler's own vptr store
   _vt$10D_00689850 resolves to 0x00689850. A real C++ constructor is needed for the
   original's instruction schedule (the same stores written in C come out in another order). */
struct D_00689850 : func_00578048 {
    s32 m3C;
    char data[0x80];
    D_00689850();
    virtual ~D_00689850();
};

D_00689850::D_00689850() {
    buf = data;
    cap = 0x80;
}
