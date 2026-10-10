struct Obj {
    char pad0[0x64];
    int dirty;
    char pad68[0x98 - 0x68];
    int hidden;
};

extern "C" void func_00475C88(void *ctx, Obj *obj);
extern "C" void func_00475C98(void *ctx, Obj *obj);

extern "C" void func_004852F8(Obj *self, void *ctx) {
    if (self->hidden == 0) {
        func_00475C88(ctx, self);
        if (self->dirty)
            func_00475C98(ctx, self);
    }
}
