struct Obj {
    char pad[0xEC0];
    float unkEC0;
    float unkEC4;
};

extern "C" void func_0049F7D8(float, float, float, float, float, float);
extern "C" void func_0049F640(float, float);

extern "C" void func_00397D50(Obj *self) {
    func_0049F7D8(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    func_0049F640(self->unkEC0, self->unkEC4);
}
