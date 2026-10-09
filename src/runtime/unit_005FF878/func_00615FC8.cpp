typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
};

extern "C" s32 func_00615FC8(Obj *arg0) {
    return ((arg0->unk8 >> 1) ^ 1) & 1;
}
