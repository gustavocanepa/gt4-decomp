#include "gt4/RaceInput.h"
typedef int s32;

extern void *RaceInput__vtable;
extern "C" void *func_0055F620(void *);
extern "C" void *func_00346758(void *);
extern "C" void *func_0043A0C0(void *, void *);
extern "C" void *func_0043A078(void *);

extern "C" void RaceInput__structor_0(void *arg0) {
    func_0055F620(arg0);
    ((struct RaceInput *)arg0)->unkD0 = &RaceInput__vtable;
    func_00346758((char *)arg0 + 0xd4);
    func_0043A0C0((char *)arg0 + 0x170, (char *)arg0 + 0x150);
    func_0043A078((char *)arg0 + 0x1a0);
    ((struct RaceInput *)arg0)->unk1C4 = 0x0;
    ((struct RaceInput *)arg0)->unk1CC = (void *)(0x1);
    ((struct RaceInput *)arg0)->unk1C8 = 0x0;
    ((struct RaceInput *)arg0)->unk1D0 = 0x0;
    ((struct RaceInput *)arg0)->unk1D4 = 0x0;
    ((struct RaceInput *)arg0)->unk144 = 0x0;
    ((struct RaceInput *)arg0)->unk148 = 0x0;
    ((struct RaceInput *)arg0)->unk14C = 0x0;
    ((struct RaceInput *)arg0)->unk194 = 0x0;
    ((struct RaceInput *)arg0)->unk19C = 0x0;
    ((struct RaceInput *)arg0)->unk1D8 = 0x0;
    ((struct RaceInput *)arg0)->unk1DC = 0x0;
}
