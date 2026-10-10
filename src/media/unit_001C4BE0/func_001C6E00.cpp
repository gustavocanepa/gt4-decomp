struct Elem {
    int v;
    char pad[0x2B8 - 4];
};
struct Obj {
    char pad[0x64C];
    Elem e[2];
    char pad2[0xBD0 - 0x64C - 2 * 0x2B8];
    int mBD0;
    int mBD4;
};
extern "C" void func_001C6B78(Obj *o);

extern "C" void func_001C6E00(Obj *o, int *vals, int a, int b)
{
    func_001C6B78(o);
    for (int i = 0; i < 2; i++)
        o->e[i].v = vals[i];
    o->mBD0 = a;
    o->mBD4 = b;
}
