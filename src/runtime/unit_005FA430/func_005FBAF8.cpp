typedef int s32;

struct Obj005FBAF8 {
    char pad[0x80];
    s32 unk80;
};

extern "C" void RaceCourse__clearData(s32 arg0);

extern "C" void func_005FBAF8(struct Obj005FBAF8 *arg0) {
    RaceCourse__clearData(arg0->unk80);
}
