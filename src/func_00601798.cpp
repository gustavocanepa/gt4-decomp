typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x68];
    s32 unk68;
};

extern "C" void func_00601798(struct Obj *arg0, f32 arg1) {
    arg0->unk68 = (s32)(arg1 * 128.0f);
}
