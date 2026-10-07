typedef int s32;
typedef unsigned int u32;
typedef long long s64;

struct Obj {
    s32 unk0;
    u32 unk4;
};

extern "C" s64 func_001CB8C0(Obj *arg0) {
    return ((s64)arg0->unk0 << 32) | arg0->unk4;
}
