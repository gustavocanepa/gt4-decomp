struct Obj {
    char pad0[0x10];
    int a;
    int f14;
    int b;
};

extern "C" int func_003A1E10(const char *name);
extern "C" char D_006A1478[];
extern "C" char D_006A1480[];

extern "C" void func_003A5948(Obj *o) {
    if (o->a == 0) {
        o->a = func_003A1E10(D_006A1478);
        o->b = func_003A1E10(D_006A1480);
    }
}
