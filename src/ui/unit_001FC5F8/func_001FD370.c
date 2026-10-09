typedef struct {
    char pad0[0x80];
    int f80, f84, f88, f8C;
    int f90, f94;
    char pad98[8];
    int fA0, fA4, fA8, fAC, fB0;
    void *fB4;
} Obj;
void *exception__structor_0(int);
void mpegif__structor_0(void *, int, int);
void func_001FD618(Obj *, int, int);

void func_001FD370(Obj *self, int a, int b) {
    void *p;
    self->f8C = 0;
    self->f80 = 0;
    self->f88 = 0;
    self->f84 = 0;
    p = exception__structor_0(0x40C);
    mpegif__structor_0(p, a, b);
    self->fB4 = p;
    self->f90 = a;
    self->f94 = b;
    func_001FD618(self, a, b);
    self->fA8 = 0;
    self->fA0 = 1;
    self->fA4 = -1;
    self->fAC = 0;
    self->fB0 = 0;
}
