typedef float f32;

struct S_00624980 {
    char pad[0x24];
    f32 unk24;
};

extern S_00624980 *PDISTD__global_font_manager;

extern "C" f32 func_0044DC30(void) {
    return PDISTD__global_font_manager->unk24;
}
