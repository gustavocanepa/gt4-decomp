typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_0036CDF8(s32 arg0);

extern "C" s32 func_0036CED0(Obj *arg0)
{
    return func_0036CDF8(arg0->unk10);
}
