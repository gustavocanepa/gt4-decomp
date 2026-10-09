typedef float f32;

struct Obj {
    char pad[0x28];
    f32 unk28;
};

extern "C" f32 func_00284218(Obj *arg0) {
    return (360.0f / arg0->unk28) * 60.0f;
}
