struct Src {
    char pad[0x58];
    int id;
    int handle;
};

struct Obj {
    int m0;
    Obj *self;
    char pad[0x54];
    int sema;
    int ready;
    int id;
};

extern "C" void func_00565310(void);
extern "C" void func_00553AF8(int handle, Src *src, void (*cb)(void));
extern "C" int func_005782E8(int a, int b);

extern "C" void func_005656E8(Obj *o, Src *src)
{
    int id = src->id;
    if (o->ready == 0) {
        func_00553AF8(src->handle, src, func_00565310);
        o->m0 = 0;
        o->self = o;
        o->sema = func_005782E8(1, 1);
        o->id = id;
        o->ready = 1;
    }
}
