typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x18];
    s32 unk18;
    char pad2[4];
    f32 unk20;
};

extern "C" void RaceRankDisplay__setRank(Obj *arg0, s32 arg1, s32 arg2) {
    if ((arg0->unk18 == 0) || (arg2 == 0)) {
        arg0->unk20 = (f32)arg1;
    }
    arg0->unk18 = arg1;
}
