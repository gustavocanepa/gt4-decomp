typedef int s32;

struct Obj {
    s32 unk0;
};

extern "C" s32 func_005943C0(Obj **arg0) {
    return (((*arg0)->unk0 >> 3) ^ 1) & 1;
}
