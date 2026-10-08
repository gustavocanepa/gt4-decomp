typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Obj {
    char pad[0x30];
    Vec3 unk30;
};

extern "C" void func_00425F50(Obj *arg0, Vec3 *arg1) {
    arg0->unk30.x = arg1->x;
    arg0->unk30.y = arg1->y;
    arg0->unk30.z = arg1->z;
}
