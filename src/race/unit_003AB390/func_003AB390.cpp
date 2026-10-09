typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x1C];
    s32 unk1C;
    f32 unk20;
    f32 unk24;
};

extern "C" void func_003AB390(Obj *arg0) {
    arg0->unk20 = 2.0f;
    arg0->unk24 = 0.9439252019f;
    arg0->unk1C = 0;
}
