struct Obj {
    char pad0[0x14];
    int active;
    int id;
};

extern char D_0064CCC0[];
extern "C" void func_00578230(void *table, int id, int flag);
extern "C" void func_00553A10(Obj *self);
extern "C" void func_00565C30(Obj *self, int a, int b, int c, int d, int e);

extern "C" void func_00565AD0(Obj *self) {
    func_00578230(D_0064CCC0, self->id, 0);
    func_00553A10(self);
    self->active = 1;
    func_00565C30(self, 0, 0, 0, 0, 1);
}
