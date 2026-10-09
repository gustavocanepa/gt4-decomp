typedef float f32;

struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct Obj {
    char pad[0x44];
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
};

extern "C" void func_003D6908(Obj *arg0, Vec4 *arg1) {
    arg0->unk44 = arg1->x;
    arg0->unk48 = arg1->y;
    arg0->unk4C = arg1->z;
    arg0->unk50 = arg1->w;
}
