typedef int s32;

struct Obj {
    char pad[0xEC];
    s32 unkEC;
    s32 unkF0;
};

extern "C" s32 func_005CD630(Obj *arg0) {
    return arg0->unkF0 != arg0->unkEC;
}
