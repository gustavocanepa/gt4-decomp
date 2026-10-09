typedef unsigned int u32;

struct Obj {
    char pad0[0x4C];
    u32 unk4C;
};

extern "C" u32 func_00328A38(Obj *arg0) {
    u32 temp = ((arg0->unk4C * 3) + 1) >> 1;
    if ((u32)(temp - 1) < 0x1D) {
        return 0x1E;
    }
    return temp;
}
