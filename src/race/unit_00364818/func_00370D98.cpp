typedef float f32;
typedef int s32;

struct Struct_00370D98 {
    char pad0[0x4C];
    s32 unk4C;
};

extern "C" void func_00370D98(Struct_00370D98 *arg0, f32 fparg0) {
    arg0->unk4C = (s32)(fparg0 * 100.0f);
}
