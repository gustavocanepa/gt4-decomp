typedef float f32;

struct Obj { char pad[0x98]; f32 unk98; };

extern "C" f32 func_0044FAA0(Obj *arg0) {
    return arg0->unk98;
}
