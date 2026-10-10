typedef int s32;

/* The base class; its constructor is func_00577DF0. Its vptr sits at 0x4. */
struct func_00577DF0 {
    s32 m0;
    func_00577DF0(s32, s32);
    virtual ~func_00577DF0();
};

/* Named after its vtable so the compiler-made vptr store _vt$10D_00689E00 resolves. */
struct D_00689E00 : func_00577DF0 {
    s32 m8;
    s32 mC;
    D_00689E00(s32 x, s32 a, s32 b);
    virtual ~D_00689E00();
};

D_00689E00::D_00689E00(s32 x, s32 a, s32 b) : func_00577DF0(a, b) {
    mC = x;
}
