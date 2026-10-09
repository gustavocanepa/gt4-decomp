typedef float f32;

struct Obj { char pad[0x6F4]; f32 unk6F4; char pad2[0x700 - 0x6F4 - 4]; f32 unk700; };

extern "C" void func_00230EC0(Obj *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = arg0->unk6F4;
    *arg2 = arg0->unk700;
}
