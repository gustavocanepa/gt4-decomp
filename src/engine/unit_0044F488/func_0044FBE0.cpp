typedef int s32;

struct Obj {
    char pad[0x100];
    s32 unk100;
    s32 unk104;
};

extern "C" s32 func_0044FBE0(struct Obj *arg0) {
    return arg0->unk100;
}

extern "C" void func_0044FBE8(struct Obj *arg0, s32 arg1) {
    arg0->unk100 = arg1;
}

extern "C" s32 func_0044FBF0(struct Obj *arg0) {
    return arg0->unk104;
}

extern "C" void func_0044FBF8(struct Obj *arg0, s32 arg1) {
    arg0->unk104 = arg1;
}
