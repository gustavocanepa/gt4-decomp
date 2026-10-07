typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_0054B8C0(s32 arg0);

extern "C" s32 func_001D1838(Obj *arg0)
{
    return func_0054B8C0(arg0->unk4);
}
