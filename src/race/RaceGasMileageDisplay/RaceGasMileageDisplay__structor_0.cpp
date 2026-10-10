#include "gt4/RaceGasMileageDisplay.h"
extern "C" void *RaceValueDisplayBase__structor_1(void *arg0);
extern "C" char RaceGasMileageDisplay__vtable[];

extern "C" void RaceGasMileageDisplay__structor_0(struct RaceGasMileageDisplay *arg0)
{
    RaceValueDisplayBase__structor_1(arg0);
    arg0->unk68 = 0;
    arg0->unk14 = RaceGasMileageDisplay__vtable;
}
