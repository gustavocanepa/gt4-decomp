typedef int s32;

struct Obj {
    char pad[0xD38];
    s32 unkD38;
    char pad2[0xD50 - 0xD38 - 4];
    s32 unkD50;
};

extern "C" s32 func_0038A2B0(Obj *arg0) {
    if (arg0->unkD50 > 0) {
        return 1;
    }
    return arg0->unkD38;
}
