typedef float f32;

/* CameraBase, named after its constructor so that __13func_0044F188 resolves */
struct CameraBase__structor_0 {
    CameraBase__structor_0();
    virtual ~CameraBase__structor_0();
};

/* a camera class with no known name: named after its vtable */
struct D_006883F8 : CameraBase__structor_0 {
    char pad[0x4C];
    f32 f50;
    f32 f54;
    D_006883F8();
    virtual ~D_006883F8();
};

D_006883F8::D_006883F8() {
    f50 = 15.0f;
    f54 = 0x1.999998p-1f;
}
