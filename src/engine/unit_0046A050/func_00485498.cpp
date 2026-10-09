typedef int s32;

struct Obj {
    char pad[0x4];
    s32 *unk4;
};

extern "C" s32 func_00485498(struct Obj *arg0, s32 arg1) {
    s32 *ptr = arg0->unk4 + arg1;
    return *ptr;
}
