typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" f32 func_006017D0(struct Obj *arg0) {
    return (f32)arg0->unk70 * 0.0078125f;
}
