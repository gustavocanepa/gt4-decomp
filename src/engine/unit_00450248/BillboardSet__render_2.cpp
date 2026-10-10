struct Obj {
    char pad[0x10];
    unsigned short count;
};

extern "C" void func_00450558(Obj *o);
extern "C" void BillboardSet__render(Obj *o, int i);
extern "C" void BillboardSet__end(Obj *o);

extern "C" void BillboardSet__render_2(Obj *o) {
    if (o == 0)
        return;
    func_00450558(o);
    for (int i = 0; i < o->count; i++)
        BillboardSet__render(o, i);
    BillboardSet__end(o);
}
