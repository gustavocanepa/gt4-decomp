typedef int s32;

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_00540F78(Obj *arg0, s32 *arg1) {
    if (arg0 == 0) {
        return 2;
    }
    *arg1 = arg0->unk4;
    return 0;
}
