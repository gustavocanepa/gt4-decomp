typedef float f32;

struct S00395400;

extern "C" f32 RaceCourse__getGoalVCoord(S00395400 *arg0);

struct Obj {
    char pad0[0xCBD8];
    S00395400 *ptr;
};

extern "C" f32 DynamicsConductor__GetGoalV(Obj *arg0) {
    return RaceCourse__getGoalVCoord(arg0->ptr);
}
