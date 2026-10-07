typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_00437320(s32 arg0);

extern "C" s32 func_005CC928(Obj *arg0)
{
    return func_00437320(arg0->unk10);
}
