typedef float f32;

struct Obj { char pad[0x244]; f32 unk244; };

extern "C" f32 mGTShirtPS2__virtual_60(Obj *arg0) {
    return arg0->unk244;
}
