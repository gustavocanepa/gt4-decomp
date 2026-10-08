typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0xC];
    s32 unk10;
};

extern "C" s32 func_004A91B8(Obj *arg0) {
    return arg0->unk0 + (arg0->unk10 << 4);
}
