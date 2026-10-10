typedef int s32;

struct Obj {
    char pad0[0x80];
    s32 unk80;
};

extern "C" s32 RaceCourse__getCheckPointCount(s32 arg0, s32 arg1);

extern "C" s32 RaceOrganization__getLoggerCheckPointCount(Obj *arg0) {
    return RaceCourse__getCheckPointCount(arg0->unk80, 1);
}
