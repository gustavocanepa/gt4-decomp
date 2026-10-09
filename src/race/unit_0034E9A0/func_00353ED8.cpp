typedef signed char s8;

struct Obj { char pad[0x633]; s8 unk633; };

extern "C" void func_00353ED8(Obj *arg0) {
    arg0->unk633 = 0x1E;
}
