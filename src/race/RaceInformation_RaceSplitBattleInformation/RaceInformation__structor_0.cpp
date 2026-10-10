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

extern char RaceInformation__vtable[];
extern char D_006A2718[];
extern char D_006A2728[];
extern char D_006A2738[];
extern "C" void func_00446F90(void);
extern "C" void func_003BFB10(void *);
extern "C" void * func_00329858(void *, void *);

struct RaceInformation__structor_0_arg0 {
    char pad0[0x110];
    s64 unk110;
    s32 unk118;
    s32 unk11C;
    s32 unk120;
    s32 unk124;
    s32 unk128;
    s32 unk12C;
};

extern "C" void RaceInformation__structor_0(s32 *arg0) {
    s32 buf0[4];
    char *v_s1;
    v_s1 = (char *)arg0 + 0xb0;
    ((struct RaceInformation__structor_0_arg0 *)arg0)->unk12C = (s32)&RaceInformation__vtable;
    func_00446F90();
    func_003BFB10(v_s1);
    ((struct RaceInformation__structor_0_arg0 *)arg0)->unk110 = (s64)0;
    ((struct RaceInformation__structor_0_arg0 *)arg0)->unk118 = 0;
    ((struct RaceInformation__structor_0_arg0 *)arg0)->unk128 = -0x1;
    ((struct RaceInformation__structor_0_arg0 *)arg0)->unk11C = 0;
    ((struct RaceInformation__structor_0_arg0 *)arg0)->unk120 = 0;
    ((struct RaceInformation__structor_0_arg0 *)arg0)->unk124 = 0;
    func_00329858(buf0, &D_006A2718);
    func_00329858((char *)arg0 + 0x120, &D_006A2728);
    func_00329858((char *)arg0 + 0x124, &D_006A2738);
    *(s32 *)(char *)v_s1 = buf0[0];
}
