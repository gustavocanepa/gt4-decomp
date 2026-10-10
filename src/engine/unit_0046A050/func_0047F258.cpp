struct Elem { int a, b; };

struct Array {
    Elem *data;
    int count;
    Elem *begin() { return data; }
    Elem *end() { return data + count; }
};

struct Obj {
    char pad[0x20];
    Array items;
};

extern "C" void func_0047E910(void *ctx);
extern "C" void func_0047F380(Elem *e, void *ctx, float t);

extern "C" void func_0047F258(Obj *o, void *ctx, float t) {
    func_0047E910(ctx);
    Elem *end = o->items.end();
    for (Elem *e = o->items.begin(); e != end; e++)
        func_0047F380(e, ctx, t);
}
