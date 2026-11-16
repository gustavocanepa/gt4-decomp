#include "types.h"

extern "C" void func_00174148(void *arg0, void *arg1);
extern "C" void func_001740F0(void *arg0, int arg1);
extern "C" void func_0017E588(void *arg0, void *arg1);
extern "C" void func_0017D268(void *arg0, int arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" int __dynamic_cast_2(void *arg0, void *arg1, int arg2, void *arg3, void *arg4, void *arg5);
extern char D_005D1E70[];
extern char D_005D1260[];

extern "C" void MMemoryCardFile__get_list(void **arg0, void *arg1) {
    s32 buf0[4];
    s32 var;
    void *obj;

    func_00174148(buf0, arg1);
    obj = *(void **)((char *)buf0[0] + 0x10);
    var = 0;
    if (obj != 0) {
        char *desc = *(char **)((char *)obj + 0x4C);
        var = __dynamic_cast_2(*(void **)(desc + 4), D_005D1E70, 0,
                            (char *)obj + *(s16 *)desc, D_005D1260, obj);
    }
    func_001740F0(buf0, 2);
    if (var != 0) {
        func_0017E588(buf0, *(void **)(var + 0x50));
        if ((void *)arg0 != (void *)buf0) {
            void *newVal = (void *)buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            void *oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_0017D268(buf0, 2);
    }
}
