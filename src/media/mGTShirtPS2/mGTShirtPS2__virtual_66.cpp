typedef float f32;

struct Obj { char pad[0x250]; f32 unk250; };

extern "C" f32 mGTShirtPS2__virtual_66(Obj *arg0) {
    return arg0->unk250;
}
