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

extern char D_00695510[];
extern char D_00695528[];
extern char D_00695540[];
extern char D_00695558[];
extern char D_00695570[];
extern "C" void func_004AE230(void *, void *, s32);
extern "C" void func_00454410(s32);
extern "C" void func_00427698(s32);
extern "C" void func_0044E500(void);

extern "C" void func_001D5078(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    func_004AE230(buf0, &D_00695510, 0x1);
    *(s32 *)(char *)arg0 = buf1[0];
    func_00454410(buf1[0]);
    func_004AE230(buf0, &D_00695528, 0x1);
    *(s32 *)((char *)arg0 + 0x4) = buf1[0];
    func_00454410(buf1[0]);
    func_004AE230(buf0, &D_00695540, 0x1);
    *(s32 *)((char *)arg0 + 0x8) = buf1[0];
    func_00454410(buf1[0]);
    func_004AE230(buf0, &D_00695558, 0x1);
    *(s32 *)((char *)arg0 + 0xc) = buf1[0];
    func_00427698(buf1[0]);
    func_004AE230(buf0, &D_00695570, 0x1);
    *(s32 *)((char *)arg0 + 0x10) = buf1[0];
    func_00427698(buf1[0]);
    func_0044E500();
}
