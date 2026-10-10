/* compiler: ee-gcc2.96-as2004 */
/* The base class, named after its constructor (func_003AEBA8); its vptr sits after 0x14 bytes. */
struct func_003AEBA8 {
    char pad[0x14];
    func_003AEBA8();
    virtual ~func_003AEBA8();
};

/* A member object, named after its constructor. */
struct func_003A9608 {
    func_003A9608();
    int m0;
};

/* Named after its vtable (0x0067E448) so that _vt$10D_0067E448 resolves. */
struct D_0067E448 : func_003AEBA8 {
    int m18;
    int slots[6];
    char pad[0xC];
    int m40;
    int m44;
    func_003A9608 m48;
    D_0067E448();
    virtual ~D_0067E448();
};

D_0067E448::D_0067E448()
{
    m18 = 0;
    for (int i = 5; i >= 0; i--)
        slots[i] = 0;
    m40 = 0;
    m44 = 0;
}
