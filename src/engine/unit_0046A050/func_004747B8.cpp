struct Obj {
    char pad[0x6E14];
    int handle;
    char pad2[0x18];
    int depth;
};

extern "C" void func_004745E8(Obj *o, int a, int b, int c, int d);
extern "C" void func_004735F8(int handle);

extern "C" void func_004747B8(Obj *o)
{
    if (--o->depth != 0)
        return func_004745E8(o, 3, 0, 3, 0x80);
    func_004745E8(o, 2, 2, 1, 0);
    func_004735F8(o->handle);
}
