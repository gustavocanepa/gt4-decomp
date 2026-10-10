typedef float f32;

struct Obj {
    char pad[0x1C];
    f32 unk1C;
    f32 unk20;
};

extern "C" void RaceMeterBase__setScale(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk1C = fparg0;
    arg0->unk20 = fparg1;
}
