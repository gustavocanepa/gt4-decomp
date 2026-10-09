typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x14];
    f32 scale;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
};

extern "C" s32 func_001063A8(Obj *);
extern "C" void func_00106710(Obj *);
extern "C" s32 func_005525F0();

extern "C" void func_001062E8(Obj *self, s32 flag) {
    self->unk1C = 1;
    self->unk18 = 0;
    self->unk20 = func_005525F0() == 2;
    self->unk30 = -1;
    self->scale = 1.0f;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    if (flag != 0) {
        func_001063A8(self);
        return;
    }
    func_00106710(self);
}
