typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_0054BB30(s32 arg0);

extern "C" s32 func_001D17A8(Obj *arg0)
{
    return func_0054BB30(arg0->unk4);
}
