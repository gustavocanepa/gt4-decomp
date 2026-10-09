typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x60];
    s32 unk60;
};

extern "C" void func_00601748(struct Obj *arg0, f32 arg1) {
    arg0->unk60 = (s32)(arg1 * 128.0f);
}
