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

extern "C" s32 func_00450AD0(void *);
extern "C" void func_003EDA10(s32);
extern "C" void func_003EDA90(s32);
extern "C" void func_0044F4B0(void);
extern "C" void func_00575DA0(s32);
extern "C" void HumanModel__virtual_03(void *);

extern "C" void RaceCarModel__virtual_01(s32 *arg0) {
    func_003EDA10(func_00450AD0((char *)arg0 + 0x18));
    if (*(s32 *)((char *)arg0 + 0x10) != 0) {
        func_003EDA90(*(s32 *)((char *)arg0 + 0x10));
        *(s32 *)((char *)arg0 + 0x10) = 0;
    }
    if (*(s32 *)((char *)arg0 + 0xc) != 0) {
        func_0044F4B0();
        func_003EDA90(*(s32 *)((char *)arg0 + 0xc));
        *(s32 *)((char *)arg0 + 0xc) = 0;
    }
    if (*(s32 *)((char *)arg0 + 0x14) != 0) {
        func_00575DA0(*(s32 *)((char *)arg0 + 0x14));
        *(s32 *)((char *)arg0 + 0x14) = 0;
    }
    *(s32 *)((char *)arg0 + 0x1670) = 0;
    *(s32 *)((char *)arg0 + 0x1674) = 0;
    HumanModel__virtual_03((char *)arg0 + 0x5e0);
    HumanModel__virtual_03((char *)arg0 + 0xe20);
}
