typedef int s32;

struct Obj {
    char pad[0x28];
    s32 unk28;
};

extern "C" s32 hClass__virtual_06(Obj *arg0) {
    return --arg0->unk28 == 0;
}
