typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x78];
    s32 unk78;
};

extern "C" void func_00601838(struct Obj *arg0, f32 arg1) {
    arg0->unk78 = (s32)(arg1 * 128.0f);
}
