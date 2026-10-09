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

extern "C" void func_0049AC70(void *);
extern "C" s32 func_00105830(void *);
extern "C" void func_0049AC98(void *, s32, s32, s32, s32);
extern "C" void func_0049AF00(void *, s32, s32);
extern "C" void func_0049B148(void *, s32, s32, s32);
extern "C" void func_0049AFD0(void *, s32, s32);

extern "C" void func_00105930(s32 *arg0, void *arg1) {
    func_0049AC70(arg1);
    func_0049AC98(arg1, 0, *(s32 *)(char *)arg0, *(s32 *)((char *)arg0 + 0x4), func_00105830(arg0));
    func_0049AF00(arg1, *(s32 *)((char *)arg0 + 0x18), *(s32 *)((char *)arg0 + 0x1c));
    func_0049B148(arg1, 0, *(s32 *)((char *)arg0 + 0x10), (*(s32 *)((char *)arg0 + 0x10) + *(s32 *)((char *)arg0 + 0x18)) - 0x1);
    func_0049B148(arg1, 0x1, *(s32 *)((char *)arg0 + 0x14), (*(s32 *)((char *)arg0 + 0x14) + *(s32 *)((char *)arg0 + 0x1c)) - 0x1);
    func_0049AFD0(arg1, 0x4, 0x2);
    func_0049AFD0(arg1, 0x5, 0x2);
}
