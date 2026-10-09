typedef float f32;

struct Obj { char pad[0x24C]; f32 unk24C; };

extern "C" f32 mGTShirtPS2__virtual_64(Obj *arg0) {
    return arg0->unk24C;
}
