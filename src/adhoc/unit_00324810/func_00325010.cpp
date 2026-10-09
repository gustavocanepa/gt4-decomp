typedef int s32;

extern "C" s32 func_00324FF0(void *arg0);
extern "C" void func_005D4AD8(const char *fmt, ...);
extern char D_0069E8B8[];

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_00325010(Obj *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    arg0->unk0 = arg3;
    arg0->unk4 = arg4;
    arg0->unk8 = arg5;
    arg0->unkC = 0;
    func_005D4AD8(D_0069E8B8, arg1, arg2);
    return func_00324FF0(arg0);
}
