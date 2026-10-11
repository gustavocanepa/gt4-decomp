#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002F9B38(s32, s32);                /* extern */
s32 func_005C1628(s32 *);                       /* extern */

extern char IfScriptEvent__vtable[];
extern char MEventFilter__vtable[];
void MEventFilter__structor_4(s32 *arg0, s32 arg1) {
    *arg0 = (s32)IfScriptEvent__vtable;
    func_002F9B38(arg0 + 1, 2);
    *arg0 = (s32)MEventFilter__vtable;
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
