typedef float f32;

struct Obj002E2C40 {
    char pad[0x3C];
    f32 unk3C;
    f32 unk40;
};

extern "C" void func_002E2C40(struct Obj002E2C40 *arg0) {
    arg0->unk3C = 1.0f;
    arg0->unk40 = 0.1f;
}
