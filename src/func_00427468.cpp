typedef int s32;

struct Obj {
    char pad[0xD4];
    s32 unkD4;
    s32 unkD8;
};

extern "C" s32 func_00427468(Obj *arg0) {
    s32 t = arg0->unkD4;
    return (arg0->unkD8 ^ t) & t;
}
