typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Obj00427800 {
    f32 unk0;
    f32 unk4;
    s32 unk8;
    char pad0[0x10 - 0x8 - 4];
    s32 unk10;
    s32 unk14;
};

extern "C" void func_00427800(struct Obj00427800 *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    arg0->unk0 = fparg0;
    arg0->unk4 = fparg1;
    arg0->unk14 = (s32)0x8FFFFFFFu;
    arg0->unk8 = arg1;
    arg0->unk10 = 0;
}
