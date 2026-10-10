typedef int s32;
typedef long long s64;

struct Obj {
    char pad0[0x98];
    s64 unk98;
};

extern "C" s32 SPEC_DATABASE__RaceSpec__loadEnemyInfo(Obj *arg0, s64 arg1);

extern "C" s32 func_006034B8(Obj *arg0) {
    return SPEC_DATABASE__RaceSpec__loadEnemyInfo(arg0, arg0->unk98);
}
