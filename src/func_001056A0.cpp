typedef int s32;
typedef float f32;

struct S_001056A0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    s32 unk28;
    s32 unk2C;
};

extern "C" void func_004A2478(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" void func_004A2D20(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" void func_004A5FE0(s32 arg0);
extern "C" void func_004A2A10(s32 arg0);
extern "C" void func_004A2B10(f32 arg0, f32 arg1);

extern "C" void func_001056A0(S_001056A0 *arg0) {
    func_004A2478(arg0->unk0, arg0->unk4, arg0->unk8, arg0->unkC);
    func_004A2D20(arg0->unk10, arg0->unk14, arg0->unk18, arg0->unk1C);
    func_004A5FE0(arg0->unk2C);
    func_004A2A10(arg0->unk28);
    func_004A2B10(arg0->unk20, arg0->unk24);
}
