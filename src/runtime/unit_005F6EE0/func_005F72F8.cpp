typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_00396800(s32 arg0);

extern "C" s32 func_005F72F8(Obj *arg0)
{
    return func_00396800(arg0->unk4);
}
