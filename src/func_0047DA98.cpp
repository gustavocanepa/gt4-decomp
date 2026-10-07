typedef float f32;

struct Obj { char pad[0x3C]; f32 unk3C; };

extern "C" f32 func_0047DA98(Obj *arg0) {
    return arg0->unk3C;
}
