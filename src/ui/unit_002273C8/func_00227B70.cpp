struct Mutex;
extern "C" void func_00576788(Mutex *m);
extern "C" void func_005767C0(Mutex *m);

struct Guard {
    Mutex *m;
    Guard(Mutex *mutex) : m(mutex) { func_00576788(m); }
    ~Guard() { func_005767C0(m); }
};

struct Table;
extern "C" int func_005DA940(Table *t, int a, int b);

struct Obj {
    char pad[0x10];
    char table[0x110];
    char mutex[4];
};

extern "C" int func_00227B70(Obj *o, int a, int b)
{
    Table *t = (Table *)o->table;
    Guard g((Mutex *)o->mutex);
    return func_005DA940(t, a, b);
}
