typedef float f32;

struct Obj {
    char pad[0x494];
    f32 unk494;
    char pad2[0x644 - 0x498];
    f32 unk644;
    int unk648;
};

extern "C" void func_003F9CF0(Obj *arg0) {
    f32 tmp = arg0->unk494;
    arg0->unk648 = 0;
    arg0->unk644 = tmp;
}
