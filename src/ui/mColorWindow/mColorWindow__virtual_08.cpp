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

extern char mColorWindow__tf[];
extern char hObject__tf[];
extern "C" void mComposite__virtual_08(void);
extern "C" s32 func_005C0FC8(s32, void *, s32, void *, void *, void *);
extern "C" void func_005E49B0(void *, s32);

extern "C" void mColorWindow__virtual_08(s32 *arg0, void *arg1) {
    s32 v_s1;
    v_s1 = 0;
    mComposite__virtual_08();
    if (arg1 != 0) {
        v_s1 = func_005C0FC8(*(s32 *)((char *)(*(s32 *)((char *)arg1 + 0x4)) + 0x4), &mColorWindow__tf, 0, (char *)arg1 + (s32)*(s16 *)(char *)(*(s32 *)((char *)arg1 + 0x4)), &hObject__tf, arg1);
    }
    if (v_s1 != 0) {
        if ((char *)arg0 + 0xb0 != (char *)(v_s1 + 0xb0)) {
            func_005E49B0((char *)arg0 + 0xb0, v_s1 + 0xb0);
        }
        *(s32 *)((char *)arg0 + 0xc0) = *(s32 *)((char *)v_s1 + 0xc0);
    }
}
