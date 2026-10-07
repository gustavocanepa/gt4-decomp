typedef int s32;

struct Obj {
    char pad[0x64];
    s32 unk64;
};

struct Arg1 {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_00554058(Obj *arg0, Arg1 *arg1, s32 arg2, s32 arg3) {
    arg1->unk0 = arg2;
    arg1->unk4 = arg3;
    arg0->unk64 = arg0->unk64 + 1;
}
