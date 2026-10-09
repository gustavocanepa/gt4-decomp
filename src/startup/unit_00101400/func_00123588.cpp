typedef unsigned char u8;
typedef float f32;

struct Obj {
    char pad[2];
    u8 unk2;
};

extern "C" f32 func_00123588(struct Obj *arg0) {
    return (f32)arg0->unk2 / 255.0f;
}
