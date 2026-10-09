typedef int s32;

struct Obj {
    char pad[0x68];
    s32 unk68;
};

extern "C" void func_00109748(Obj *arg0);

extern "C" void CarIconMaker__virtual_01(Obj *arg0) {
    arg0->unk68 = 0;
    func_00109748(arg0);
}
