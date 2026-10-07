typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_004373F0(s32 arg0);

extern "C" s32 func_005CBDB8(Obj *arg0)
{
    return func_004373F0(arg0->unk10);
}
