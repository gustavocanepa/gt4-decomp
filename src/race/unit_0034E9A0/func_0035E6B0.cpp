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

extern "C" s32 func_0034C190(void);
extern "C" void RaceDisplayTimeDiffEvent__structor_0(s32, void *, s32);

extern "C" void func_0035E6B0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    if (*(u8 *)((char *)arg0 + 0x10000 - 0x3424) == 0) {
        if (*(u8 *)((char *)(func_0034C190()) + 0x5b7) == 0) {
            if (*(s32 *)((char *)((*(s32 *)(char *)arg0 + (arg2 << 2))) + 0x928) != 0x157529ff) {
                RaceDisplayTimeDiffEvent__structor_0(*(s32 *)(char *)arg0, arg1, ((s32)arg3 - *(s32 *)((char *)((*(s32 *)(char *)arg0 + (arg2 << 2))) + 0x928)));
            }
        }
    }
}
