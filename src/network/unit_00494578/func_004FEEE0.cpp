typedef int s32;

struct Obj {
    char pad[0x150];
    s32 unk150;
};

extern "C" s32 func_004FEEE0(Obj *arg0) {
    if (arg0->unk150 != 0) {
        arg0->unk150 = 0;
    }
    return 1;
}
