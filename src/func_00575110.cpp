typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[4];
    u32 unk4;
};

extern "C" s32 func_00575110(Obj *arg0, Obj *arg1) {
    u32 a = arg0->unk4;
    u32 b = arg1->unk4;
    if (a < b) {
        return -1;
    }
    return b < a;
}
