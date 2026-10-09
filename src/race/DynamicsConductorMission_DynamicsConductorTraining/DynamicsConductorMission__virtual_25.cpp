typedef int s32;

struct Obj {
    char pad0[0xF864];
    char unkF864;
};

extern "C" s32 DynamicsConductorBattle2P__virtual_25(Obj *arg0);

extern "C" s32 DynamicsConductorMission__virtual_25(Obj *arg0) {
    arg0->unkF864 = 0;
    return DynamicsConductorBattle2P__virtual_25(arg0);
}
