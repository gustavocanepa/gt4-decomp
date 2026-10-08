typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_004398B0(s32 arg0);

extern "C" s32 func_005CD218(struct Obj *arg0) {
    return func_004398B0(arg0->unk10 + 0x1650);
}
