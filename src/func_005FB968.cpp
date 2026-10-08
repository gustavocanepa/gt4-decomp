typedef int s32;

struct Target {
    char pad[0x343C];
    s32 unk343C;
};

struct Inner {
    char pad[0x8];
    Target **unk8;
};

struct Obj {
    char pad[0x60];
    Inner *unk60;
};

extern "C" s32 func_005FB968(Obj *arg0, s32 arg1) {
    return arg0->unk60->unk8[arg1]->unk343C;
}
