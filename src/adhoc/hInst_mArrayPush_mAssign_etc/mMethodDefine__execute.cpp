#include "types.h"

s32 func_002F47F0(s32);
void func_002F4848(s32, s32);
s32 func_002F36A0(s32, char *, s32);
void *func_00322060(s32);
s32 __dynamic_cast_2(s32, s32, s32, s32, s32, s32);

extern char hClass__tf[];
extern char hModule__tf[];

s32 mMethodDefine__execute(char *arg0, s32 arg1) {
    char *temp_v0;
    char *temp_t;
    char *p2;
    char *p1;
    s32 var_s0;

    p2 = arg0;
    p1 = p2 + 0xC;
    if (func_002F47F0(*(s32 *)p1) == 0) {
        var_s0 = 0;
        temp_v0 = (char *)func_00322060(arg1);
        if (temp_v0 != 0) {
            temp_t = *(char **)(temp_v0 + 4);
            var_s0 = __dynamic_cast_2(*(s32 *)(temp_t + 4), (s32)hClass__tf, 0,
                                   (s32)(temp_v0 + *(s16 *)temp_t), (s32)hModule__tf,
                                   (s32)temp_v0);
        }
        if (var_s0 != 0) {
            func_002F4848(*(s32 *)p1, var_s0);
            return func_002F36A0(var_s0, p2 + 8, (s32)p1);
        }
    }
}
