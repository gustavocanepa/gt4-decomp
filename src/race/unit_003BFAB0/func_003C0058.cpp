typedef int s32;

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" s32 RaceCourse__getCheckPoint(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_003C0058(struct Obj *arg0, s32 arg1) {
    return RaceCourse__getCheckPoint(arg0->unk80, arg1, 0);
}
