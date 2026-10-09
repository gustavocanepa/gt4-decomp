typedef float f32;

struct Obj00421AE8 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

extern "C" f32 func_00421AE8(struct Obj00421AE8 *arg0, f32 fparg0) {
    return ((arg0->unk8 * fparg0) + arg0->unk4) * fparg0 + arg0->unk0;
}
