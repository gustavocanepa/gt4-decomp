typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" f32 func_00601870(struct Obj *arg0) {
    return (f32)arg0->unk80 * 0.0078125f;
}
