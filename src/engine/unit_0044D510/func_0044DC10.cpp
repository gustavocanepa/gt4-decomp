typedef float f32;

struct Obj {
    char pad[0x24];
    f32 unk24;
    f32 unk28;
};

extern struct Obj *PDISTD__global_font_manager;

extern "C" void func_0044DC10(f32 fparg0, f32 fparg1) {
    struct Obj *temp_v1 = PDISTD__global_font_manager;
    temp_v1->unk24 = fparg0;
    temp_v1->unk28 = fparg1;
}

extern "C" void func_0044DC28(void) {
}
