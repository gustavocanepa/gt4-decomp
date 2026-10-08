typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x60];
    s32 unk60;
};

extern "C" f32 func_00601730(struct Obj *arg0) {
    return (f32)arg0->unk60 * 0.0078125f;
}
