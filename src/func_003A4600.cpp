typedef int s32;

/* The base class; its constructor is func_003AEBA8. Its vptr sits at 0x14. */
struct func_003AEBA8 {
    char pad[0x14];
    func_003AEBA8();
    virtual ~func_003AEBA8();
};

struct D_0067F8A8;
extern "C" void func_003A4650(D_0067F8A8 *);

/* Named after its vtable so the compiler-made vptr store _vt$10D_0067F8A8 resolves. */
struct D_0067F8A8 : func_003AEBA8 {
    char pad18[0x8];
    s32 m20;
    char pad24[0x20];
    float m44;
    D_0067F8A8();
    virtual ~D_0067F8A8();
};

D_0067F8A8::D_0067F8A8() {
    func_003A4650(this);
    m20 = 3;
    m44 = 0.9f;
}
