#define GT4_CXX
#include "gt4/RaceLicense.h"

extern "C" void RaceLoggerBuffer__clearSector(s32 arg0);

extern "C" void RaceSolitaire__initializeLogger(RaceLicense *arg0)
{
    RaceLoggerBuffer__clearSector(arg0->getLoggerBuffer());
}
