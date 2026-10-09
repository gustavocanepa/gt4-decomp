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

extern "C" void func_00576788(void);
extern "C" s32 func_00575620(void *, void *);
extern "C" void func_005767C0(void *);

extern "C" s32 func_005754B0(s32 *arg0, void *arg1) {
    s32 v_s0;
    s32 t1;
    func_00576788();
    t1 = func_00575620(arg0, arg1);
    v_s0 = 0;
    if (t1 >= 0) {
        v_s0 = *(s32 *)((char *)((*(s32 *)((char *)arg0 + 0x4c) + (t1 << 3))) + 0x4) + 0x4;
        if (((*(s32 *)(char *)(*(s32 *)((char *)((*(s32 *)((char *)arg0 + 0x4c) + (t1 << 3))) + 0x4)) ^ 0x1) & 0x1) != 0) {
            *(s32 *)(char *)(*(s32 *)((char *)((*(s32 *)((char *)arg0 + 0x4c) + (t1 << 3))) + 0x4)) = (*(s32 *)(char *)(*(s32 *)((char *)((*(s32 *)((char *)arg0 + 0x4c) + (t1 << 3))) + 0x4)) | 0x1);
            *(s32 *)((char *)arg0 + 0x54) = *(s32 *)((char *)arg0 + 0x54) + 0x1;
        }
    }
    func_005767C0(arg0);
    return v_s0;
}
