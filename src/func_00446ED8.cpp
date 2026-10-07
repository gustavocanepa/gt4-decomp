typedef long long s64;

struct Obj {
    char pad0[0xF0];
    s64 unkF0;
};

extern "C" void func_00446E60(s64 arg0);

extern "C" void func_00446ED8(Obj *arg0) {
    func_00446E60(arg0->unkF0);
}
