typedef int s32;

struct Obj {
    char pad0[0xE4];
    s32 unkE4;
};

extern "C" s32 GetADPsource(s32 arg0);

extern "C" s32 func_00466C08(Obj *arg0)
{
    return GetADPsource(arg0->unkE4);
}
