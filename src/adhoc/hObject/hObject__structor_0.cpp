#include "gt4/hObject.h"
extern "C" void *RefCounter__structor_0(void *arg0);
extern "C" char hObject__vtable[];

extern "C" void hObject__structor_0(struct hObject *arg0)
{
    RefCounter__structor_0(arg0);
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk4 = hObject__vtable;
}
