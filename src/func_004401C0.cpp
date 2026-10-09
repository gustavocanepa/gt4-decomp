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

extern "C" void func_0043FE58(void);
extern "C" void func_0043FEA0(void *, void *);
extern "C" void func_0043FEF0(void *, void *);
extern "C" void func_0043FF40(void *, void *);
extern "C" void func_0043FF90(void *, void *);
extern "C" void func_0043FFE0(void *, void *);
extern "C" void func_00440030(void *, void *);
extern "C" void func_00440080(void *, void *);
extern "C" void func_004400D0(void *, void *);
extern "C" void func_00440120(void *, void *);
extern "C" void func_00440170(void *, void *);

extern "C" void func_004401C0(s32 *arg0, void *arg1) {
    func_0043FE58();
    func_0043FEA0(arg0, arg1);
    func_0043FEF0(arg0, arg1);
    func_0043FF40(arg0, arg1);
    func_0043FF90(arg0, arg1);
    func_0043FFE0(arg0, arg1);
    func_00440030(arg0, arg1);
    func_00440080(arg0, arg1);
    func_004400D0(arg0, arg1);
    func_00440120(arg0, arg1);
    func_00440170(arg0, arg1);
}
