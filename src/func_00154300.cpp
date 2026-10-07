typedef float f32;

struct Obj { char pad[0x8C]; f32 unk8C; };

extern "C" void func_00154300(Obj *arg0, f32 arg1) {
    arg0->unk8C = arg1;
}
