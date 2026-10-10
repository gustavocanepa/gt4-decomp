#include "gt4/RaceChampionshipInformation.h"
typedef int s32;

extern "C" void RaceChampionshipInformation__finishEntryCar_FirstSession(struct RaceChampionshipInformation *arg0);
extern "C" void RaceChampionshipInformation__finishEntryCar_Continue(void);

extern "C" void RaceChampionshipInformation__finishEntryCar(struct RaceChampionshipInformation *arg0) {
    if (arg0->unk170 == 0) {
        return RaceChampionshipInformation__finishEntryCar_FirstSession(arg0);
    }
    RaceChampionshipInformation__finishEntryCar_Continue();
}
