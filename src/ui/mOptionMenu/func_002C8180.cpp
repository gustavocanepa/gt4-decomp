typedef int s32;

struct Obj {
    char pad[0xD8];
    s32 unkD8;
};

extern "C" s32 func_002C8100(Obj *arg0, s32 arg1);

extern "C" s32 func_002C8180(Obj *arg0)
{
    return func_002C8100(arg0, arg0->unkD8);
}
