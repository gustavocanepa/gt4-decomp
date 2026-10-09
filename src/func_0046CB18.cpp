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

extern "C" void func_0046F378(void *, s32);
extern "C" void func_0046F300(void *, s32);

extern "C" void func_0046CB18(s32 *arg0) {
    char *v_s0;
    v_s0 = (char *)arg0 + 0x85c;
    func_0046F378(v_s0, (0 | 0xffda));
    func_0046F378(v_s0, 0xc);
    func_0046F300(v_s0, 0x3);
    func_0046F300(v_s0, 0);
    func_0046F300(v_s0, 0);
    func_0046F300(v_s0, 0x1);
    func_0046F300(v_s0, 0x11);
    func_0046F300(v_s0, 0x2);
    func_0046F300(v_s0, 0x11);
    func_0046F300(v_s0, 0);
    func_0046F300(v_s0, 0x3f);
    func_0046F300(v_s0, 0);
}
