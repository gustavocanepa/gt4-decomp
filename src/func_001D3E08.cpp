typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" s32 func_001D3E08(Obj *arg0) {
    return (arg0->unk4 - arg0->unk0) + 0x8006;
}
