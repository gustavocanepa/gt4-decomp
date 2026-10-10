#include "gt4/RaceChampionshipInformation.h"
typedef int s32;

extern "C" void func_003EEDA8(struct RaceChampionshipInformation *arg0);
extern "C" void func_003EEEC8(void);

extern "C" void RaceChampionshipInformation__virtual_13(struct RaceChampionshipInformation *arg0) {
    if (arg0->unk170 == 0) {
        return func_003EEDA8(arg0);
    }
    func_003EEEC8();
}
