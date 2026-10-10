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
extern "C" void func_0045B4D8(void *, void *, void *);
extern "C" void func_0045AF18(void *, s32);
extern "C" s32 func_003B5A20(void *, s32, s32, void *);
extern "C" void func_0045B040(void *, s32);
extern "C" s32 func_003B5AF8(void *, void *);
extern "C" s32 func_003B5B80(void *, void *);
extern "C" void func_0045AF38(void *, s32);
extern "C" void func_0045B548(void *, void *);

struct func_0033A1B0_arg1 {
    char pad0[0x345C];
    s32 unk345C;
};

extern "C" void func_0033A1B0(s32 *arg0, struct func_0033A1B0_arg1 *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    func_0045B4D8(buf0, arg0, &D_0069F308);
    func_0045AF18(arg0, 0x1);
    p_s1 = buf1;
    func_0045B040(arg0, func_003B5A20(arg1, 0x1, arg2, p_s1));
    func_0045B040(arg0, func_003B5A20(arg1, 0, arg2, p_s1));
    func_0045B040(arg0, func_003B5AF8(arg1, p_s1));
    func_0045B040(arg0, func_003B5B80(arg1, p_s1));
    func_0045AF38(arg0, arg1->unk345C);
    func_0045B548(buf0, arg0);
}
