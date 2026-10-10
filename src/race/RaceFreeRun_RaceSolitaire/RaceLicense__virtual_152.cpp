#define GT4_CXX
#include "gt4/RaceLicense.h"

extern "C" void func_003BDB48(s32 arg0);

extern "C" void RaceLicense__virtual_152(RaceLicense *arg0)
{
    func_003BDB48(arg0->getLoggerBuffer());
}
