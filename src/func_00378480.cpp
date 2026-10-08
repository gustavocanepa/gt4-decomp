typedef int s32;

struct Obj {
    char pad[0xF28];
    s32 unkF28;
    char pad2[0x8];
    s32 unkF34;
};

extern "C" s32 func_00378480(Obj *arg0) {
    s32 v0 = arg0->unkF34 != 1;
    if (arg0->unkF28 != 0) v0 = 0;
    return v0;
}
