typedef float f32;

struct Struct_0027B430 {
    char pad0[0x2C];
    f32 unk2C;
};

extern "C" void func_0028A968(Struct_0027B430 *arg0, f32 arg1) {
    arg0->unk2C = 1.0f / (arg1 * 60.0f);
}
