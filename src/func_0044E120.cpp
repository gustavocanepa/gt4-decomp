struct Obj {
    int a;
    int b;
};

extern "C" void func_0044E1E0(Obj *self, int b);
extern "C" void func_00491418(void *mgr, int x, int y, int one, int zero);
extern "C" void func_0044E348(Obj *self);
extern void *D_00624980;

extern "C" void func_0044E120(Obj *self, int x, int y)
{
    func_0044E1E0(self, self->b);
    func_00491418(D_00624980, x, y, 1, 0);
    func_0044E348(self);
}
