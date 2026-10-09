typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_00430D20(s32 arg0);

extern "C" s32 func_001A6E28(Obj *arg0)
{
    return func_00430D20(arg0->unk10);
}
