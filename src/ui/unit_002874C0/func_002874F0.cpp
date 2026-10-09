typedef float f32;

struct Struct_00287400 {
    char pad0[0x24];
    f32 unk24;
};

extern "C" void func_002874F0(Struct_00287400 *arg0, f32 arg1) {
    arg0->unk24 = 1.0f / (arg1 * 60.0f);
}
