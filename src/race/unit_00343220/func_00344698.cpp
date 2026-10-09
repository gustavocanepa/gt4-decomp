typedef float f32;

struct Obj { char pad[0x58C]; f32 unk58C; };

extern "C" f32 func_00344698(Obj *arg0) {
    return arg0->unk58C;
}
