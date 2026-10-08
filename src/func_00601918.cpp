typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x8C];
    s32 unk8C;
};

extern "C" void func_00601918(struct Obj *arg0, f32 arg1) {
    arg0->unk8C = (s32)(arg1 * 128.0f);
}
