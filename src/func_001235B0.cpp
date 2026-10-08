typedef unsigned char u8;
typedef float f32;

struct Obj {
    char pad[3];
    u8 unk3;
};

extern "C" f32 func_001235B0(struct Obj *arg0) {
    return (f32)arg0->unk3 / 255.0f;
}
