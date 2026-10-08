typedef int s32;
typedef long long s64;

struct Obj {
    char pad0[0x1E8];
    s32 unk1E8;
};

extern "C" s64 func_0044A5A8(s32 arg0);

extern "C" s64 func_00603460(Obj *arg0) {
    return func_0044A5A8(arg0->unk1E8);
}
