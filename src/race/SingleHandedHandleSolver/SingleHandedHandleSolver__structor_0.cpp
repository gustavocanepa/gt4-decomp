/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Vec3_00415CD8 {
    f32 x, y, z, pad;
    Vec3_00415CD8() : x(0.0f), y(0.0f), z(0.0f) {}
};

struct HandleSolverBase {
    s32 m0;
    char pad4[0xC];
    Vec3_00415CD8 m10;
    Vec3_00415CD8 m20;
    Vec3_00415CD8 m30;
    f32 m40, m44, m48;
    HandleSolverBase(s32 a) __asm__("HandleSolverBase__structor_0");
    virtual ~HandleSolverBase();
};

struct SingleHandedHandleSolver : HandleSolverBase {
    Vec3_00415CD8 m50;
    f32 m60;
    f32 m64;
    f32 m68;
    f32 m6C;
    f32 m70;
    s32 m74;
    SingleHandedHandleSolver(s32 a);
    virtual ~SingleHandedHandleSolver();
};

SingleHandedHandleSolver::SingleHandedHandleSolver(s32 a)
    : HandleSolverBase(a), m60(0.0f), m64(0.0f), m68(0.0f), m6C(0.0f), m70(0.0f), m74(0) {
}
