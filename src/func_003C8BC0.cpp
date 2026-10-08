typedef int s32;

extern "C" s32 func_00388E00(void *arg0);

struct Obj003C8BC0 {
    char pad0[0x2EF30];
    s32 unk2EF30;
};

extern "C" s32 func_003C8BC0(struct Obj003C8BC0 *arg0) {
    if (arg0->unk2EF30 != 0) {
        return 4;
    }
    return func_00388E00(arg0);
}
