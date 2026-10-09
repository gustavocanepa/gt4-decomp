typedef int s32;

struct Obj003EE788 {
    char pad0[0x170];
    s32 unk170;
};

extern "C" void func_003EEDA8(struct Obj003EE788 *arg0);
extern "C" void func_003EEEC8(void);

extern "C" void RaceChampionshipInformation__virtual_13(struct Obj003EE788 *arg0) {
    if (arg0->unk170 == 0) {
        return func_003EEDA8(arg0);
    }
    func_003EEEC8();
}
