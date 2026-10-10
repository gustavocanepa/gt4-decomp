struct Pair {
    unsigned char a;
    unsigned char b;
    void set(int x, int y) { a = x; b = y; }
};

struct Obj {
    char pad0[0x44];
    Pair mode;
    char pad46[0x3A];
    int arg80;
    char pad84[0x54];
    char mat[0xC];
    float fe4;
    int ie8;
    char vec[0xC];
    float ff8;
    int ifc;
};

extern "C" void func_00370548(Obj *self, void *mat, int arg);
extern "C" void func_005F5040(void *mat, void *vec);

extern "C" void func_00370BE0(Obj *self)
{
    self->mode.set(0, 0x18);
    func_00370548(self, self->mat, self->arg80);
    func_005F5040(self->mat, self->vec);
    self->ff8 = self->fe4;
    self->ifc = self->ie8;
}
