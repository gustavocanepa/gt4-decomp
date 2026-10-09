typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x2C];
    s32 unk2C;
    char pad30[0x70 - 0x30];
    f32 unk70;
};

extern Obj *D_00624980;

extern "C" void func_0044DFA0(f32 fparg0) {
    if (fparg0 > 0.0f) {
        D_00624980->unk2C = 1;
    }
    D_00624980->unk70 = fparg0;
}
