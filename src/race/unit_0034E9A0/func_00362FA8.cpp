struct Info {
    unsigned char pad;
    unsigned char count;
};

struct Obj {
    char pad[0x10];
    int id;
};

extern "C" Info *func_00359510(int id);
extern "C" void func_00362E58(Obj *o, int i);

extern "C" void func_00362FA8(Obj *o)
{
    Info *info = func_00359510(o->id);
    for (int i = 0; i < info->count; i++)
        func_00362E58(o, i);
}
