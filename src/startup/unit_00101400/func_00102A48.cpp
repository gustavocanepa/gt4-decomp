struct Obj {
    char pad0[0x6C];
    char mutex[0x40];
    int count;
};

extern "C" void func_00576788(void *mutex);
extern "C" void func_005767C0(void *mutex);
extern "C" void func_0010AB78(Obj *self);

extern "C" void func_00102A48(Obj *self) {
    func_00576788(self->mutex);
    int n = self->count;
    if (n < 3) {
        self->count = ++n;
        if (n == 3)
            func_0010AB78(self);
    }
    func_005767C0(self->mutex);
}
