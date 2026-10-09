typedef float f32;

struct Obj { char pad[0x24]; f32 unk24; };

extern "C" void func_0021A7F0(Obj *arg0, f32 arg1) {
    arg0->unk24 = arg1;
}
