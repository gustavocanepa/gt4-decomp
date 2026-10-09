typedef float f32;

struct Struct_0027B400 {
    char pad0[0x2C];
    f32 unk2C;
};

extern "C" f32 func_0028A938(Struct_0027B400 *arg0) {
    return 1.0f / (arg0->unk2C * 60.0f);
}
