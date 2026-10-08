typedef int s32;

struct Target {
    char pad[0x345C];
    s32 unk345C;
};

struct Inner {
    char pad[0x8];
    Target **unk8;
};

struct Obj {
    char pad[0x60];
    Inner *unk60;
};

extern "C" void func_003C0DD8(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk60->unk8[arg2]->unk345C = arg1;
}
