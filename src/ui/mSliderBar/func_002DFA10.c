#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0057CD90(void *, s32, s32);
struct func_002DFA10_arg0 {
    char pad0[0xCC];
    s32 unkCC;
    char padD0[0x10];
    s32 unkE0;
    s32 unkE4;
    char padE8[0xC];
    f32 unkF4;
};

void func_002DFA10(void *arg0, s32 arg1, s32 arg2) {
    ((struct func_002DFA10_arg0 *)arg0)->unkE0 = arg1;
    ((struct func_002DFA10_arg0 *)arg0)->unkE4 = arg2;
    func_0057CD90((s8 *)arg0 + 0xCC, arg1, arg2 + 1);
    ((struct func_002DFA10_arg0 *)arg0)->unkF4 = (f32) ((struct func_002DFA10_arg0 *)arg0)->unkCC;
}
