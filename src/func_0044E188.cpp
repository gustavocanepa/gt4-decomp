struct Obj { int m0; int handle; };
extern "C" void func_0044E1E0(Obj *self, int handle);
extern "C" void func_00491418(void *sys, int arg, int a, int b, int c);
extern "C" void func_0044E348(Obj *self);
extern "C" void *D_00624980;

extern "C" void func_0044E188(Obj *self, int arg)
{
    func_0044E1E0(self, self->handle);
    func_00491418(D_00624980, arg, 0, 0, 0);
    func_0044E348(self);
}
