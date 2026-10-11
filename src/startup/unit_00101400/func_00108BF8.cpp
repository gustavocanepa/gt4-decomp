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

extern "C" s32 func_00579358(void);
extern "C" void malloc(s32);
extern "C" s32 func_0043A490(void);
extern "C" void func_001092D0(void);
extern "C" void func_00103B80(void);
extern "C" void func_00102758(void);
extern "C" void func_00108CB8(void);
extern "C" void func_0010AFC8(void);
extern "C" void func_00101D60(void);
extern "C" void func_0044A5B0(void);
extern "C" void func_0044B3A0(void);
extern "C" void func_00103D20(void);
extern "C" void func_0043A500(s32);
extern "C" void func_0010B268(void);

extern "C" void func_00108BF8(s32 *arg0) {
    s32 v_s0;
    malloc(((func_00579358() & 0x3f) + 0x1 << 4));
    v_s0 = func_0043A490();
    func_001092D0();
    func_00103B80();
    func_00102758();
    func_00108CB8();
    func_0010AFC8();
    func_00101D60();
    func_0044A5B0();
    func_0044B3A0();
    func_00103D20();
    func_0043A500(v_s0);
    func_0010B268();
}
