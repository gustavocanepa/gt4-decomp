typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" s32 func_00441248(s32 arg0);
extern "C" s32 func_00445A50(s32 arg0, s32 arg1);

extern "C" s32 func_00145E00(Obj *arg0, s32 arg1) {
    s32 s0 = arg1;
    s32 v0 = func_00441248(arg0->unk14);
    return func_00445A50(v0, s0);
}
