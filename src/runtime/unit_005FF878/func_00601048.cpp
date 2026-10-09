typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_00601048(struct Obj *arg0) {
    return arg0->unkC >= arg0->unk8;
}
