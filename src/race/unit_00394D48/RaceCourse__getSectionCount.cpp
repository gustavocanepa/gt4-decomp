typedef int s32;
typedef unsigned short u16;

struct S00395200 {
    char pad0[0x4];
    s32 unk4;
};

struct S00396800_ret {
    char pad0[0x54];
    u16 unk54;
};

extern "C" struct S00396800_ret *CourseData__getRunway(s32 arg0);

extern "C" u16 RaceCourse__getSectionCount(struct S00395200 *arg0) {
    return CourseData__getRunway(arg0->unk4)->unk54;
}
