typedef float f32;
typedef int s32;

struct C;

struct Obj002BA278 {
    char pad0[0x14];
    struct C *unk14;
    char pad1[0x1C - 0x14 - 4];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

extern "C" void func_0025B538(struct C *c, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void mMagnifyActor__rewind(struct Obj002BA278 *arg0) {
    struct C *temp_v0 = arg0->unk14;

    if (temp_v0 != 0) {
        func_0025B538(temp_v0, arg0->unk1C, arg0->unk20, arg0->unk24, arg0->unk28);
    }
}
