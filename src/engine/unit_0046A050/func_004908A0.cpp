typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x30];
    f32 unk30;
    f32 unk34;
    char pad2[0x4C - 0x38];
    s32 unk4C;
};

extern "C" void func_004908A0(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk4C = 0;
    arg0->unk30 = (f32)arg1;
    arg0->unk34 = (f32)arg2;
}
