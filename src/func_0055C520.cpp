struct Lock;
extern Lock D_00655340;
extern "C" void func_00576100(Lock *l);
extern "C" void func_00576140(Lock *l);

struct Obj {
    char pad[0xA0];
    int counter;
};

extern "C" int func_0055C520(Obj *o)
{
    func_00576100(&D_00655340);
    int id = o->counter;
    o->counter = id + 1;
    if (id == 0x7FFFFFFF)
        id = 0;
    func_00576140(&D_00655340);
    return id;
}
