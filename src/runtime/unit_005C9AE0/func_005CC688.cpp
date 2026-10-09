typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_00437260(s32 arg0);

extern "C" s32 func_005CC688(Obj *arg0)
{
    return func_00437260(arg0->unk10);
}
