typedef float f32;

struct Obj0044E390 {
    char pad[0x18];
    f32 unk18;
    f32 unk1C;
};

extern "C" void func_0044E390(struct Obj0044E390 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk18 = fparg0;
    arg0->unk1C = fparg1;
}
