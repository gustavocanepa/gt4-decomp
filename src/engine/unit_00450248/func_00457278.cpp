typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_004569D0(void *, void *);
extern "C" void func_004569F0(void *, s32, s32, s32);

struct func_00457278_arg0 {
    char pad0[0x38];
    s32 unk38;
    char pad3C[0x20];
    s32 unk5C;
};
struct func_00457278_arg3 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_00457278(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s2;
    if ((arg2 < (s32)*(u16 *)((char *)arg0 + 0x16))) {
        if (arg3 != 0) {
            v_s2 = *(s32 *)((char *)((((s32)arg1 << 2) + ((((arg2 << 2) + arg2) << 3) + ((struct func_00457278_arg0 *)arg0)->unk38))) + 0x1c);
            if (v_s2 >= 0) {
                func_004569D0(buf0, arg3);
                func_004569F0(buf0, ((struct func_00457278_arg0 *)arg0)->unk5C, v_s2, ((struct func_00457278_arg3 *)arg3)->unk14);
            }
        }
    }
}
