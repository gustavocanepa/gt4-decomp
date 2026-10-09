typedef long long s64;

struct Obj {
    char pad0[0x100];
    s64 unk100;
};

extern "C" void func_00446EF8(s64 arg0);

extern "C" void func_00446F70(Obj *arg0) {
    func_00446EF8(arg0->unk100);
}
