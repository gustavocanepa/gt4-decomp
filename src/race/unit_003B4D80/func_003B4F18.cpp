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

extern "C" void func_004452F8(void *);

extern "C" void func_003B4F18(s32 *arg0, void *arg1) {
    char *v_s0;
    v_s0 = (char *)arg0 + 0x20;
    func_004452F8(v_s0);
    *(s32 *)((char *)v_s0 + 0x178) = *(s32 *)((char *)arg0 + 0x14) + 0x100;
    if (*(s8 *)((char *)arg1 + 0x166) != 0) {
        *(s32 *)((char *)arg0 + 0x3448) = *(s32 *)((char *)arg1 + 0x178);
        *(s32 *)((char *)arg0 + 0x3450) = *(s32 *)((char *)arg1 + 0x17c);
        *(s32 *)((char *)arg0 + 0x3454) = *(s32 *)((char *)arg1 + 0x180) != 0;
    }
    *(s32 *)((char *)arg0 + 0x344c) = *(s32 *)((char *)arg1 + 0x184);
    *(s32 *)((char *)arg0 + 0x3458) = *(s32 *)((char *)arg1 + 0x188);
}
