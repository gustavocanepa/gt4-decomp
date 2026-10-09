typedef int s32;

struct Obj {
    char pad[0x40];
    s32 unk40;
};

extern "C" s32 func_00104CA0(Obj *arg0) {
    return (arg0->unk40 != 0) ? 1 : -1;
}
