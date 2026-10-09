typedef int s32;

struct Obj {
    char pad[0xCC4];
    s32 unkCC4;
};

extern "C" s32 func_004F9E60(Obj *arg0, s32 arg1);

extern "C" s32 func_0060F000(Obj *arg0) {
    return func_004F9E60(arg0, arg0->unkCC4);
}
