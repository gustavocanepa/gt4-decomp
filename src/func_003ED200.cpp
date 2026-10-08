typedef int s32;

struct RaceMission {
    char pad0[0x125F8];
    s32 unk125F8;
    s32 unk125FC;
};

extern "C" void func_003ED200(RaceMission *arg0, s32 arg1) {
    arg0->unk125F8 = arg1;
    arg0->unk125FC = 0;
}
