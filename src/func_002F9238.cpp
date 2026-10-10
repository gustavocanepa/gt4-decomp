/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

/* The base class, named after its copy constructor (func_0030A6B0) so that
   __13func_0030A6B0RC13func_0030A6B0 resolves. The vptr sits after its 4 bytes of data. */
struct func_0030A6B0 {
    s32 m0;
    func_0030A6B0(const func_0030A6B0 &);
    virtual ~func_0030A6B0();
};

/* No known name: named after its vtable (0x00673D60) so that _vt$10D_00673D60 resolves.
   A real C++ copy constructor gives the original's register homes and scheduling. */
struct D_00673D60 : func_0030A6B0 {
    s32 m8;
    s32 mC;
    f32 m10;
    D_00673D60(const D_00673D60 &o);
    virtual ~D_00673D60();
};

D_00673D60::D_00673D60(const D_00673D60 &o) : func_0030A6B0(o), m10(o.m10) {
}
