typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_00601888(struct Obj *arg0, f32 arg1) {
    arg0->unk80 = (s32)(arg1 * 128.0f);
}
