typedef long long s64;

struct Obj {
    char pad[0xA0];
    s64 unkA0;
};

extern "C" s64 func_00447548(struct Obj *arg0) {
    return arg0->unkA0;
}
