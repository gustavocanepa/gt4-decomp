typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x88];
    s32 unk88;
};

extern "C" void func_006018D8(struct Obj *arg0, f32 arg1) {
    arg0->unk88 = (s32)(arg1 * 128.0f);
}
