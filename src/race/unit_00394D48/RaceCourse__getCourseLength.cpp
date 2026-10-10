typedef int s32;
typedef float f32;

struct S00395400 {
    char pad0[0x4];
    s32 unk4;
};

struct S00396800_ret {
    char pad0[0x14];
    f32 unk14;
};

extern "C" struct S00396800_ret *CourseData__getRunway(s32 arg0);

extern "C" f32 RaceCourse__getCourseLength(struct S00395400 *arg0) {
    return CourseData__getRunway(arg0->unk4)->unk14;
}
