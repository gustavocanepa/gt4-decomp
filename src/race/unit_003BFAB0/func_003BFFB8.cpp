typedef int s32;

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void RaceCourse__clearData(s32 arg0);
extern char RaceCourse__model_arena_;

extern "C" void *func_003BFFB8(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk80;

    if (temp_v0 != 0) {
        RaceCourse__clearData(temp_v0);
    }
    return &RaceCourse__model_arena_;
}
