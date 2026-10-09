typedef float f32;

struct Obj {
    char pad0[0xC];
    f32 unkC;
    char pad1[0x1C - 0xC - 4];
    f32 unk1C;
};

extern "C" f32 func_003700B0(Obj *arg0, f32 fparg0) {
    return (arg0->unkC * fparg0) / arg0->unk1C;
}
