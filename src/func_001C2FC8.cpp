typedef float f32;

struct Obj { char pad[0x24C]; f32 unk24C; };

extern "C" f32 func_001C2FC8(Obj *arg0) {
    return arg0->unk24C;
}
