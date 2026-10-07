typedef int s32;

struct Obj {
    char pad0[0x60];
    s32 unk60;
};

extern "C" s32 func_00474A40(s32 arg0);

extern "C" s32 func_00480620(Obj *arg0)
{
    return func_00474A40(arg0->unk60);
}
