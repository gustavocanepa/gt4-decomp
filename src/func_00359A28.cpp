typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" s32 func_00359A28(Obj *arg0, s32 arg1) {
    arg0->unk8 = arg1;
    return 1;
}
