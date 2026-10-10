extern char D_00687418[];
extern "C" void func_004A1638(int code);

struct Obj {
    int a;
    void *vt;
    int b;
    int slots[8];
    int owner;
};

extern "C" void func_0042CEA8(Obj *self, int owner)
{
    self->owner = owner;
    self->a = 0;
    self->b = 0;
    self->vt = D_00687418;
    for (int i = 7; i >= 0; i--)
        self->slots[i] = 0;
    if (self->owner == 0)
        func_004A1638(100);
}
