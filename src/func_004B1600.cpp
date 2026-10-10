/* The base class, named after its constructor (func_004B0960); its vptr sits at 0xA4. */
struct func_004B0960 {
    char pad[0xA4];
    func_004B0960(int a, int b, int c);
    virtual ~func_004B0960();
};

/* Named after its vtable (0x00689178) so that _vt$10D_00689178 resolves. */
struct D_00689178 : func_004B0960 {
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    int mB8;
    int mBC;
    D_00689178(int b4, int b, int a, int c, int bc);
    virtual ~D_00689178();
};

D_00689178::D_00689178(int b4, int b, int a, int c, int bc) : func_004B0960(a, b, c)
{
    mBC = bc;
    mB0 = a == 0;
    mB4 = b4;
    mB8 = 0;
}
