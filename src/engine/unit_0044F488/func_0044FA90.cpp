typedef float f32;

struct Obj { char pad[0x90]; f32 unk90; };

extern "C" f32 func_0044FA90(Obj *arg0) {
    return arg0->unk90;
}
