typedef float f32;

struct Inner0024BE78 {
    f32 unk0;
    f32 unk4;
    char pad8[4];
    f32 unkC;
    f32 unk10;
};

struct Obj0024BE78 {
    char pad[0x10];
    struct Inner0024BE78 inner;
};

extern "C" void func_0024BE78(struct Obj0024BE78 *arg0, f32 fparg0, f32 fparg1) {
    struct Inner0024BE78 *p = &arg0->inner;
    p->unk0 = p->unk0 * fparg0;
    p->unkC = p->unkC * fparg1;
    p->unk4 = p->unk4 * fparg0;
    p->unk10 = p->unk10 * fparg1;
}
