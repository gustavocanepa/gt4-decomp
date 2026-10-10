struct Obj {
    char pad[0x10];
    unsigned short count;
};

extern "C" void func_00450558(Obj *o);
extern "C" void func_004506F0(Obj *o, int i);
extern "C" void func_004506B8(Obj *o);

extern "C" void func_00450918(Obj *o) {
    if (o == 0)
        return;
    func_00450558(o);
    for (int i = 0; i < o->count; i++)
        func_004506F0(o, i);
    func_004506B8(o);
}
