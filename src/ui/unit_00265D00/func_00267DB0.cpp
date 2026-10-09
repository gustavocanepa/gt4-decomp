typedef float f32;

struct Obj { char pad[0x88]; f32 unk88; };

extern "C" f32 func_00267DB0(Obj *arg0) {
    return arg0->unk88;
}
