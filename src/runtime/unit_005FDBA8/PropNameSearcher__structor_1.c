#include "types.h"
#include "gt4/PropNameSearcher.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char PropNameSearcher__vtable[];
s32 PropNameSearcher__structor_1(struct PropNameSearcher *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = (s32)PropNameSearcher__vtable;
}
