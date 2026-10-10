#include "gt4/mStream.h"
typedef int s32;

extern void *mStream__vtable;
extern "C" void *hObject__structor_0(void *);

extern "C" void mStream__structor_0(struct mStream *arg0) {
    hObject__structor_0(arg0);
    arg0->unk4 = &mStream__vtable;
    arg0->unk24 = 0x0;
    arg0->unk10 = 0x0;
    arg0->unk14 = 0x0;
    arg0->unk18 = 0x0;
    arg0->unk20 = 0x0;
    arg0->unk1C = (void *)(0x1);
}
