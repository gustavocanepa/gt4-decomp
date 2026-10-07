typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x1D00];
    s32 unk1D00;
};

extern "C" f32 func_002317C8(Obj *arg0) {
    return *(f32 *)((char *)arg0 + (arg0->unk1D00 * 0x38) + 0x754);
}
