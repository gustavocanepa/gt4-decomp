typedef int s32;

struct Inner {
    char pad[0x8];
    char **unk8;
};

struct Obj {
    char pad[0x60];
    Inner *unk60;
};

extern "C" char *func_005FB948(Obj *arg0, s32 arg1) {
    return arg0->unk60->unk8[arg1] + 0x1A0;
}
