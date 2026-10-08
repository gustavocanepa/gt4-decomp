typedef int s32;

struct Obj {
    char pad[0xF28];
    s32 unkF28;
    char pad2[0xF34 - 0xF28 - 4];
    s32 unkF34;
};

extern "C" s32 func_00378498(Obj *arg0) {
    s32 one = 1;
    s32 result = arg0->unkF34 == one;
    if (arg0->unkF28 != 0) {
        result = one;
    }
    return result;
}
