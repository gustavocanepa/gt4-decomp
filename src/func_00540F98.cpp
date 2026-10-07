typedef int s32;

struct Obj {
    char pad[0x210];
    s32 unk210;
};

extern "C" s32 func_00540F98(Obj *arg0, s32 *arg1) {
    if (arg0 == 0) {
        return 2;
    }
    *arg1 = arg0->unk210;
    return 0;
}
