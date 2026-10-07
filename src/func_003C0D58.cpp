typedef int s32;

struct Target {
    char pad[0x344C];
    s32 unk344C;
};

struct Inner {
    char pad[0x8];
    Target **unk8;
};

struct Obj {
    char pad[0x60];
    Inner *unk60;
};

extern "C" void func_003C0D58(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk60->unk8[arg2]->unk344C = arg1;
}
