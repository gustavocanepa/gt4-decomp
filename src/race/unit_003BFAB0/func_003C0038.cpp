typedef int s32;

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" s32 RaceCourse__getCheckPointCount(s32 arg0, s32 arg1);

extern "C" s32 func_003C0038(struct Obj *arg0) {
    return RaceCourse__getCheckPointCount(arg0->unk80, 0);
}
