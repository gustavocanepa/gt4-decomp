struct Elem { int a, b; };
extern "C" void func_0047E910(void *ctx);
extern "C" void func_0047EB20(Elem *e, void *ctx);
struct Array {
    Elem *data;
    int count;
    Elem *begin() { return data; }
    Elem *end() { return data + count; }
    void visit(void *ctx)
    {
        Elem *last = end();
        for (Elem *e = begin(); e != last; e++)
            func_0047EB20(e, ctx);
    }
};
struct Obj {
    char pad[0x10];
    Array arr;
};

extern "C" void func_0047EA08(Obj *o, void *ctx)
{
    func_0047E910(ctx);
    o->arr.visit(ctx);
}
