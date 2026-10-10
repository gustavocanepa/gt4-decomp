struct Obj {
    char pad[0x34];
    float unk34;
    float unk38;
};

extern "C" void func_00464ED8(Obj *);
extern "C" void func_00464BB0(Obj *, float);

extern "C" void func_00464E40(Obj *self) {
    func_00464ED8(self);
    func_00464BB0(self, 0.0f);
    self->unk34 = 0.0f;
    self->unk38 = 0.0f;
}
