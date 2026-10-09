typedef int s32;
typedef long long s64;

struct Obj {
    char pad0[0x98];
    s64 unk98;
};

extern "C" s32 func_004472C0(Obj *arg0, s64 arg1);

extern "C" s32 func_006034B8(Obj *arg0) {
    return func_004472C0(arg0, arg0->unk98);
}
