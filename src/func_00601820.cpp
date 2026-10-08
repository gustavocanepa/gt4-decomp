typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x78];
    s32 unk78;
};

extern "C" f32 func_00601820(struct Obj *arg0) {
    return (f32)arg0->unk78 * 0.0078125f;
}
