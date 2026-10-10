extern char D_00655340[];

extern "C" void func_00576100(void *m);
extern "C" void func_00576140(void *m);

struct Obj {
    char pad[0xA4];
    int nextId;
};

extern "C" int func_0055C588(Obj *o) {
    func_00576100(D_00655340);
    int id = o->nextId;
    int next = id + 1;
    if (next == 0x7FFFFFFF)
        next = 0;
    o->nextId = next;
    func_00576140(D_00655340);
    return id;
}
