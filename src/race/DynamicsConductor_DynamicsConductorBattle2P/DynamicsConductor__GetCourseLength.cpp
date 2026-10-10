typedef float f32;

struct S00395400;

extern "C" f32 RaceCourse__getCourseLength(S00395400 *arg0);

struct Obj {
    char pad0[0xCBD8];
    S00395400 *ptr;
};

extern "C" f32 DynamicsConductor__GetCourseLength(Obj *arg0) {
    return RaceCourse__getCourseLength(arg0->ptr);
}
