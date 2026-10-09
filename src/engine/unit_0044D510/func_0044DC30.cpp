typedef float f32;

struct S_00624980 {
    char pad[0x24];
    f32 unk24;
};

extern S_00624980 *D_00624980;

extern "C" f32 func_0044DC30(void) {
    return D_00624980->unk24;
}
