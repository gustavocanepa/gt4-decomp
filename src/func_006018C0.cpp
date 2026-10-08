typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x88];
    s32 unk88;
};

extern "C" f32 func_006018C0(struct Obj *arg0) {
    return (f32)arg0->unk88 * 0.0078125f;
}
