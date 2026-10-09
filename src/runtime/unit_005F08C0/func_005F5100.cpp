typedef float f32;

struct Obj005F5100 {
    char pad0[0x1C];
    f32 unk1C;
};

extern "C" f32 func_005F5100(struct Obj005F5100 *arg0) {
    return 2.0f / arg0->unk1C;
}
