#include "types.h"
#include "gt4/MWidgetReader.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char MWidgetReader__vtable[];
s32 MWidgetReader__structor_3(struct MWidgetReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MWidgetReader__vtable;
}
