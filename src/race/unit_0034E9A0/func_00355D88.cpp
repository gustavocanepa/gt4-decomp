typedef float f32;

extern f32 D_008438DC;

struct Obj00355D88 {
    char pad[0x788];
    f32 unk788;
};

extern "C" f32 func_00355D88(struct Obj00355D88 *arg0) {
    return arg0->unk788 / D_008438DC;
}
