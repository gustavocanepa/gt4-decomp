typedef float f32;

struct DevelopCamera00371CF8 {
    char pad0[0x9C0];
    f32 unk9C0;
    char pad1[0x9D4 - 0x9C0 - 4];
    f32 unk9D4;
};

extern "C" f32 DevelopCamera__virtual_13(struct DevelopCamera00371CF8 *arg0) {
    return arg0->unk9D4 / arg0->unk9C0;
}
