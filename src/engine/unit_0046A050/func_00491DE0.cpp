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

extern s32 D_006D6180;
extern char D_006D6190[];
extern char D_0088FED0[];
extern "C" s32 func_004AB030(void);
extern "C" void pgluTexReset(void *);
extern "C" void pgluTexImage(void *, s32, s32, s32, s32);
extern "C" void func_0049AF00(void *, s32, s32);
extern "C" void func_0049AFD0(void *, s32, s32);

extern "C" void func_00491DE0(s32 *arg0) {
    char *v_s1;
    s32 t1;
    char *v_s0;
    t1 = func_004AB030();
    v_s1 = (char *)&D_006D6190;
    v_s0 = (char *)&D_0088FED0;
    *(s32 *)(char *)v_s1 = t1;
    pgluTexReset(v_s0);
    pgluTexImage(v_s0, 0, *(s32 *)(char *)v_s1, 0x14, 0x40);
    func_0049AF00(v_s0, 0x20, 0x20);
    func_0049AFD0(v_s0, 0x4, 0x2);
    func_0049AFD0(v_s0, 0x5, 0x2);
    D_006D6180 = *(s32 *)(char *)v_s1 + 0x7c0;
}
