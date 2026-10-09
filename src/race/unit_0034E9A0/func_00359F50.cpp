typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_00359F38(s32 arg0);

extern "C" s32 func_00359F50(Obj *arg0)
{
    return func_00359F38(arg0->unk10);
}
