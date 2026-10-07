typedef float f32;

struct Obj {
    char pad[0x28];
    f32 unk28;
    char pad2[0x34 - 0x28 - 4];
    int unk34;
};

extern "C" void func_002CDB20(Obj *arg0, f32 fparg0) {
    arg0->unk28 = fparg0;
    arg0->unk34 = 0;
}
