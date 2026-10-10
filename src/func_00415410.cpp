/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Vector {
    f32 x, y, z, w;
    Vector() { x = 0.0f; y = 0.0f; z = 0.0f; }
};

struct HandleSolverBase {
    s32 unk0;
    s32 pad4[3];
    Vector v10;
    Vector v20;
    Vector v30;
    f32 x40, y40, z40;
    HandleSolverBase(s32 arg) __asm__("HandleSolverBase__structor_0");
    virtual ~HandleSolverBase();
};

HandleSolverBase::HandleSolverBase(s32 arg) : unk0(arg) {
    x40 = 0.0f;
    y40 = 0.0f;
    z40 = 0.0f;
}
