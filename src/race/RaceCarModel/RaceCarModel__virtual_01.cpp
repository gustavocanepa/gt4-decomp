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

struct RaceCarModel__virtual_01_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    char pad18[0x1658];
    s32 unk1670;
    s32 unk1674;
};

extern "C" void RaceCarModel__virtual_01(s32 *arg0) {
    func_003EDA10(func_00450AD0((char *)arg0 + 0x18));
    if (((struct RaceCarModel__virtual_01_arg0 *)arg0)->unk10 != 0) {
        func_003EDA90(((struct RaceCarModel__virtual_01_arg0 *)arg0)->unk10);
        ((struct RaceCarModel__virtual_01_arg0 *)arg0)->unk10 = 0;
    }
    if (((struct RaceCarModel__virtual_01_arg0 *)arg0)->unkC != 0) {
        func_0044F4B0();
        func_003EDA90(((struct RaceCarModel__virtual_01_arg0 *)arg0)->unkC);
        ((struct RaceCarModel__virtual_01_arg0 *)arg0)->unkC = 0;
    }
    if (((struct RaceCarModel__virtual_01_arg0 *)arg0)->unk14 != 0) {
        func_00575DA0(((struct RaceCarModel__virtual_01_arg0 *)arg0)->unk14);
        ((struct RaceCarModel__virtual_01_arg0 *)arg0)->unk14 = 0;
    }
    ((struct RaceCarModel__virtual_01_arg0 *)arg0)->unk1670 = 0;
    ((struct RaceCarModel__virtual_01_arg0 *)arg0)->unk1674 = 0;
    HumanModel__virtual_03((char *)arg0 + 0x5e0);
    HumanModel__virtual_03((char *)arg0 + 0xe20);
}
