typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x68];
    s32 unk68;
};

extern "C" f32 func_00601780(struct Obj *arg0) {
    return (f32)arg0->unk68 * 0.0078125f;
}
