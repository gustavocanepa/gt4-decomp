typedef float f32;

struct Inner {
    char pad[0x2C];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
};

struct Obj {
    char pad[0xA0];
    Inner inner;
};

extern "C" void func_005DCC30(Obj *arg0) {
    Inner *p = &arg0->inner;
    p->unk2C = p->unk34;
    p->unk30 = p->unk38;
}
