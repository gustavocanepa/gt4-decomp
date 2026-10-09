typedef int s32;

struct Obj {
    char pad[0x60];
    s32 unk60;
};

extern "C" s32 func_00529028(struct Obj *arg0, s32 *arg1) {
    *arg1 = 0;
    if (arg0 == 0) {
        return 0xD2F2;
    }
    *arg1 = arg0->unk60;
    return 0;
}
