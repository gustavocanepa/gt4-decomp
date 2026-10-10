struct Obj {
    char pad0[0x166];
    unsigned char flag;
};

extern "C" void func_00444440(Obj *o, long a);
extern "C" void func_00445880(Obj *o, int b);

extern "C" void RacePlayerSpec__createEquipments(Obj *o, long a, int b, int flag) {
    func_00444440(o, a);
    func_00445880(o, b);
    o->flag = flag;
}
