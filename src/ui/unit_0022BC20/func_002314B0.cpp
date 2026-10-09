typedef float f32;

struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct Struct_002314B0 {
    char pad0[0x710];
    Vec4 unk710;
};

extern "C" void func_002314B0(struct Struct_002314B0 *arg0, Vec4 *arg1) {
    Vec4 *p = &arg0->unk710;

    if (p != arg1) {
        p->x = arg1->x;
        p->y = arg1->y;
        p->z = arg1->z;
        p->w = arg1->w;
    }
}
