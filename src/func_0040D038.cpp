typedef float f32;

struct Obj { char pad[0x5C]; f32 unk5C; };

extern "C" void func_0040D038(Obj **arg0, f32 fparg0) {
    (*arg0)->unk5C = fparg0;
}
