struct Obj {
    char pad[0x2EF34];
    int active;
    int handle;
};

extern "C" void func_00335558(int h);
extern "C" void func_00334158(int h);
extern "C" void func_003355F0(int h);

extern "C" void func_003C8A38(Obj *o)
{
    func_00335558(o->handle);
    if (o->active)
        return func_00334158(o->handle);
    func_003355F0(o->handle);
}
