typedef float f32;

struct Obj {
    char pad0[0x240C];
    f32 unk240C;
    f32 unk2410;
    f32 unk2414;
    f32 unk2418;
    f32 unk241C;
    f32 unk2420;
    f32 unk2424;
};

extern "C" void FlareClass__setReflectionFlareParameter(Obj *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6) {
    arg0->unk240C = fparg0 * 128.0f;
    arg0->unk2410 = fparg1 * 128.0f;
    arg0->unk2414 = fparg2 * 128.0f;
    arg0->unk2418 = fparg3;
    arg0->unk241C = fparg4;
    arg0->unk2420 = fparg5;
    arg0->unk2424 = fparg6;
}
