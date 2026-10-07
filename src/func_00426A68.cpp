typedef int s32;

struct Obj {
    char pad[0x198];
    s32 unk198;
    char pad2[0x1DC - 0x198 - 4];
    s32 unk1DC;
};

extern "C" s32 func_00426A68(Obj *arg0) {
    if (arg0->unk198 & 1) {
        return arg0->unk1DC;
    }
    return 0;
}
