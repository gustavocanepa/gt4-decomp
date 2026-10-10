extern "C" int func_003A1E10(const char *name);
extern "C" char D_006A17A0[];
extern "C" char D_006A17B0[];
extern "C" char D_006A17C0[];
extern "C" char D_006A17D8[];

struct Obj {
    char pad[0x18];
    int ids[4];
};

extern "C" void func_003ACDA8(Obj *o)
{
    if (o->ids[0] == 0) {
        o->ids[0] = func_003A1E10(D_006A17A0);
        o->ids[1] = func_003A1E10(D_006A17B0);
        o->ids[2] = func_003A1E10(D_006A17C0);
        o->ids[3] = func_003A1E10(D_006A17D8);
    }
}
