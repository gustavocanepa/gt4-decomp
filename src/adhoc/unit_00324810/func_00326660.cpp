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

extern char D_0084248C[];
extern char D_00842490[];
extern "C" void func_00576788(void *);
extern "C" void func_00329180(s32);
extern "C" s32 ADHOC__PoolAllocator__GetDefault(void);
extern "C" void func_00329200(s32);
extern "C" void func_005767C0(void *);

extern "C" s32 func_00326660(s32 *arg0) {
    char *v_s3;
    char *v_s0;
    s32 v_s2;
    v_s3 = (char *)&D_00842490;
    v_s0 = (char *)&D_0084248C;
    v_s2 = *(s32 *)(char *)v_s0;
    func_00576788(v_s3);
    func_00329180(*(s32 *)(char *)v_s0);
    *(s32 *)(char *)v_s0 = (s32)arg0;
    if (*(s32 *)(char *)v_s0 != ADHOC__PoolAllocator__GetDefault()) {
        func_00329200(*(s32 *)(char *)v_s0);
    }
    func_005767C0(v_s3);
    return v_s2;
}
