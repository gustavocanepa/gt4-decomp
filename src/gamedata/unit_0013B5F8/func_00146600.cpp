typedef int s32;
typedef float f32;

struct Obj00146600 {
    char pad0[0x184];
    s32 unk184;
};

extern "C" f32 func_00146600(struct Obj00146600 *arg0) {
    return (f32)arg0->unk184 / 100.0f;
}
