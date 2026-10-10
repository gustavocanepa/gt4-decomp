typedef int s32;

struct Obj {
    char pad[0x44];
    s32 unk44;
    s32 unk48;
};

extern "C" void CourseData__render_model(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void CourseData__render_after(Obj *arg0) {
    CourseData__render_model(arg0, arg0->unk44, arg0->unk48);
}
