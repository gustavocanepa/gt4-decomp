struct Params {
    int a;
    int pad4[2];
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
};

struct Info {
    int pad;
    int value;
};

struct Obj {
    int pad0;
    int id;
    int id2;
    int flagC;
    int pad10[2];
    int flag18;
    char pad1C[0x40];
    char name[0x10];
    int target;
};

extern "C" Info *func_001C93B0(int id);
extern "C" int func_001C93F0(int id);
extern "C" int func_005C1CE8(int target, char *name, Params *p);
extern char D_00693F50[];

extern "C" char *func_001CA4D8(Obj *o) {
    Params p;
    int angle = 360;
    p.a = func_001C93B0(o->id)->value;
    p.b = func_001C93F0(o->id2);
    p.c = o->flagC ? 201 : 200;
    p.d = o->flag18 ? 101 : 100;
    p.e = 400;
    p.f = angle;
    p.g = angle;
    p.h = 0;
    if (func_005C1CE8(o->target, o->name, &p))
        return D_00693F50;
    return 0;
}
