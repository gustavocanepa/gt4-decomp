#include "types.h"
#include "gt4/ResultChampionship.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 ResultArcade__structor_0();                            /* extern */

extern char ResultChampionship__vtable[];
void ResultChampionship__structor_3(struct ResultChampionship *arg0) {
    ResultArcade__structor_0();
    arg0->unk560 = 0;
    arg0->unkC = (s32)ResultChampionship__vtable;
}
