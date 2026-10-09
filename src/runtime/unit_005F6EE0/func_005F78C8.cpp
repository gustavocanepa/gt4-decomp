struct S003AE2B8;

extern "C" void func_003AE2B8(S003AE2B8 *arg0);

struct Obj {
    char pad[0x2DA0];
};

extern "C" void func_005F78C8(Obj *arg0) {
    func_003AE2B8((S003AE2B8 *)(arg0 + 1));
}
