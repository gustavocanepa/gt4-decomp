typedef int s32;

struct Elem003EF1C8 {
    char pad0[0x2F8];
    s32 unk2F8;
};

extern "C" s32 RaceChampionshipInformation__getDriversPoints(char *arg0, s32 arg1) {
    return ((struct Elem003EF1C8 *)(arg1 * 0x188 + arg0))->unk2F8;
}
