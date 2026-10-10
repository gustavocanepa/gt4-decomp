/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

/* The base class, named after its copy constructor (hObject__structor_1) so that
   __13func_0030A6B0RC13func_0030A6B0 resolves. The vptr sits after its 4 bytes of data. */
struct hObject__structor_1 {
    s32 m0;
    hObject__structor_1(const hObject__structor_1 &);
    virtual ~hObject__structor_1();
};

/* No known name: named after its vtable (0x00673D60) so that _vt$10D_00673D60 resolves.
   A real C++ copy constructor gives the original's register homes and scheduling. */
struct hFloat__vtable : hObject__structor_1 {
    s32 m8;
    s32 mC;
    f32 m10;
    hFloat__vtable(const hFloat__vtable &o);
    virtual ~hFloat__vtable();
};

hFloat__vtable::hFloat__vtable(const hFloat__vtable &o) : hObject__structor_1(o), m10(o.m10) {
}
