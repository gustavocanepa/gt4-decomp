typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_004372C0(s32 arg0);

extern "C" s32 func_005CC8F0(Obj *arg0)
{
    return func_004372C0(arg0->unk10);
}
