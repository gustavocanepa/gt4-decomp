typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

struct Obj {
    char pad[0x2FC];
    Vec3 unk2FC;
};

extern "C" void func_005E8BE8(struct Obj *arg0, Vec3 *arg1) {
    Vec3 *dst = &arg0->unk2FC;
    dst->x = arg1->x;
    dst->y = arg1->y;
    dst->z = arg1->z;
}
