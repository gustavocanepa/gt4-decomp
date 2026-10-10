typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x2C];
    s32 unk2C;
    char pad30[0x70 - 0x30];
    f32 unk70;
};

extern Obj *PDISTD__global_font_manager;

extern "C" void GT3OLDFONT__GT3OldFontManagerClass__setShadowValue(f32 fparg0) {
    if (fparg0 > 0.0f) {
        PDISTD__global_font_manager->unk2C = 1;
    }
    PDISTD__global_font_manager->unk70 = fparg0;
}
