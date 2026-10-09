typedef long s64;

struct Obj {
    char pad[0x110];
    s64 unk110;
};

extern "C" void func_004470E8(Obj *arg0);

extern "C" void RaceNetBattleInformation__virtual_19(Obj *arg0, s64 arg1) {
    arg0->unk110 = arg1;
    func_004470E8(arg0);
}
