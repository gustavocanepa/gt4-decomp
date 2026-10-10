typedef int s32;

/* A member class, named after its constructor (func_00345AE8). */
struct func_00345AE8 {
    char data[0x58];
    func_00345AE8();
};

/* No known name: named after its vtable (0x00679958); a real C++ constructor (vptr at 0x6C,
   after the data members). */
struct D_00679958 {
    s32 m0;
    s32 m4;
    func_00345AE8 sub;
    s32 m60;
    s32 m64;
    s32 m68;
    D_00679958();
    virtual ~D_00679958();
};

D_00679958::D_00679958() {
    m0 = 0;
    m4 = 0;
    m60 = 0;
    m64 = 0;
    m68 = 0;
}
