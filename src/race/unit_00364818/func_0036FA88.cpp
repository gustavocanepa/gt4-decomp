typedef int s32;

struct Obj {
    char pad[0x104];
    void *unk104;
};

extern "C" char D_0067A060[];
extern "C" s32 func_0036FAE8(Obj *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_0036FA88(Obj *arg0) {
    arg0->unk104 = D_0067A060;
    return func_0036FAE8(arg0, 0, 0);
}
