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

extern "C" void func_002B5188(void *, void *, s32);
extern "C" s32 func_002B5498(void *, s32);
extern "C" void func_002B5500(void *, s32, s32);

extern "C" void func_002B5270(s32 *arg0, void *arg1) {
    func_002B5188(arg0, arg1, 0);
    if (*(s32 *)((char *)arg0 + 0x12c) >= 0) {
        if (*(s32 *)((char *)arg0 + 0x124) != *(s32 *)((char *)arg0 + 0x12c)) {
            if (func_002B5498(arg0, *(s32 *)((char *)arg0 + 0x12c)) != 0) {
                func_002B5500(arg0, *(s32 *)((char *)arg0 + 0x12c), 0);
            }
            if (*(s32 *)((char *)arg0 + 0x124) >= 0) {
                func_002B5500(arg0, *(s32 *)((char *)arg0 + 0x124), *(s32 *)((char *)arg0 + 0x108));
            }
            *(s32 *)((char *)arg0 + 0x14c) = 0x1;
        }
    }
    *(s32 *)((char *)arg0 + 0x12c) = -0x1;
}
