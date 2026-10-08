typedef float f32;

struct Sub_003658A0 {
    char pad[0x444];
    f32 unk444;
    f32 unk448;
    f32 unk44C;
};

struct Obj_003658A0 {
    char pad[0x104];
    struct Sub_003658A0 sub;
};

extern "C" void func_003658A0(struct Obj_003658A0 *arg0) {
    struct Sub_003658A0 *s = &arg0->sub;
    f32 t = s->unk444;

    s->unk448 = t * 0.016666666f;
    s->unk44C = 60.0f / t;
}
