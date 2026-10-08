typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_004CB9C8(s32 arg0, Obj *arg1);

extern "C" s32 func_004CBA30(s32 arg0, s32 arg1, s32 arg2, Obj *arg3) {
    arg3->unk0 = arg1;
    arg3->unk4 = 0;
    arg3->unk8 = 0;
    arg3->unkC = 0;
    return func_004CB9C8(arg0, arg3);
}
