typedef int s32;

/* The base class, named after its constructor (func_0042A5B8) so that __13func_0042A5B8iii
   resolves. The vptr sits after its 4 bytes of data. */
struct func_0042A5B8 {
    s32 m0;
    func_0042A5B8(s32, s32, s32);
    virtual ~func_0042A5B8();
};

/* No known name: named after its vtable (0x006867B0) so that _vt$10D_006867B0 resolves. */
struct D_006867B0 : func_0042A5B8 {
    char pad[0x20];
    s32 m28;
    s32 m2C;
    D_006867B0(s32 arg);
    virtual ~D_006867B0();
};

D_006867B0::D_006867B0(s32 arg) : func_0042A5B8(arg, 0, 0), m28(0), m2C(0) {
}
