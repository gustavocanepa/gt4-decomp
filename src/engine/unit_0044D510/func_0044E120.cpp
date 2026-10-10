struct Obj {
    int a;
    int b;
};

extern "C" void func_0044E1E0(Obj *self, int b);
extern "C" void func_00491418(void *mgr, int x, int y, int one, int zero);
extern "C" void func_0044E348(Obj *self);
extern void *PDISTD__global_font_manager;

extern "C" void func_0044E120(Obj *self, int x, int y)
{
    func_0044E1E0(self, self->b);
    func_00491418(PDISTD__global_font_manager, x, y, 1, 0);
    func_0044E348(self);
}
