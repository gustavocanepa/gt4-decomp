typedef float f32;

struct Struct_00287400 {
    char pad0[0x24];
    f32 unk24;
};

extern "C" f32 func_002874C0(Struct_00287400 *arg0) {
    return 1.0f / (arg0->unk24 * 60.0f);
}
