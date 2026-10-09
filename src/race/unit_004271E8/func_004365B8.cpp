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

extern s32 D_006184F0;
extern char D_006244D8[];
extern "C" void func_004A0BE0(s32, s32);
extern "C" s32 func_004390D0(void *);
extern "C" void func_00472528(void *, s32);
extern "C" void func_00439888(void *);
extern "C" void func_00460AF8(s32);

extern "C" void func_004365B8(s32 *arg0) {
    char *v_s1;
    s32 t1;
    v_s1 = (char *)&D_006244D8;
    func_004A0BE0((*(s32 *)((char *)arg0 + 0x18) << 1), (*(s32 *)((char *)arg0 + 0x1c) << 1));
    t1 = func_004390D0((char *)arg0 + 0x24);
    D_006184F0 = t1;
    func_00472528(v_s1, *(s32 *)((char *)arg0 + 0xc));
    *(s32 *)(char *)v_s1 = (s32)*(u8 *)((char *)arg0 + 0x10);
    *(s32 *)((char *)v_s1 + 0x4) = (s32)*(u8 *)((char *)arg0 + 0x11);
    *(s32 *)((char *)v_s1 + 0x8) = (s32)*(u8 *)((char *)arg0 + 0x12);
    func_00439888((char *)arg0 + 0x1650);
    func_00460AF8(*(s32 *)((char *)arg0 + 0x10b0));
}
