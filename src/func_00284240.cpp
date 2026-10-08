typedef float f32;

struct Obj {
    char pad0[0x28];
    f32 unk28;
};

extern "C" void func_00284240(Obj *arg0, f32 arg1) {
    arg0->unk28 = 360.0f / (arg1 * 60.0f);
}
