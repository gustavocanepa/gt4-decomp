typedef float f32;

struct Obj {
    char pad[0x20];
    f32 unk20;
};

extern f32 D_006A14C4;

extern "C" void func_003A5D10(Obj *arg0) {
    arg0->unk20 = D_006A14C4;
}
