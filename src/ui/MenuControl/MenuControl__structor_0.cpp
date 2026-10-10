#include "gt4/MenuControl.h"
typedef int s32;

extern "C" s32 func_0055F6A0(void *arg0, s32 arg1, s32 arg2);
extern char MenuControl__vtable[];

extern "C" void MenuControl__structor_0(struct MenuControl *arg0)
{
    (void)func_0055F6A0(arg0, 0, 0);
    arg0->unkD0 = MenuControl__vtable;
}
