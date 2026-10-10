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

extern char D_0069F308[];
extern "C" void func_0045B620(void *, void *);
extern "C" s32 func_0045B348(void *, void *);
extern "C" s32 func_0045B0F8(void *);
extern "C" s32 func_0045B228(void *);
extern "C" void func_003B6B08(void *, s32, s32);
extern "C" void func_003B6B38(void *, s32);
extern "C" void func_003B6B58(void *, s32);
extern "C" s32 func_0045B118(void *);
extern "C" void func_0045B740(void *, void *);

struct func_0033A8C0_arg1 {
    char pad0[0x345C];
    s32 unk345C;
};

struct func_0033A8C0_arg0 {
    char pad0[0x8];
    s32 unk8;
};

extern "C" void func_0033A8C0(s32 *arg0, struct func_0033A8C0_arg1 *arg1) {
    s32 buf0[4];
    s32 v_s3;
    s32 v_s0;
    s32 v_s1;
    s32 v_s2;
    func_0045B620(buf0, arg0);
    if (func_0045B348(buf0, &D_0069F308) == 0) {
        ((struct func_0033A8C0_arg0 *)arg0)->unk8 = (*(s32 *)(char *)arg0 + buf0[1]);
    } else {
        v_s3 = func_0045B0F8(arg0);
        v_s0 = func_0045B228(arg0);
        func_0045B228(arg0);
        v_s1 = func_0045B228(arg0);
        v_s2 = func_0045B228(arg0);
        func_003B6B08(arg1, 0x1, v_s0);
        func_003B6B08(arg1, 0, v_s0);
        func_003B6B38(arg1, v_s1);
        func_003B6B58(arg1, v_s2);
        if (v_s3 > 0) {
            arg1->unk345C = func_0045B118(arg0);
        }
        func_0045B740(buf0, arg0);
    }
}
