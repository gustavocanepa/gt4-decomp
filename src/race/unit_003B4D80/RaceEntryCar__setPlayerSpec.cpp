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

extern "C" void func_004452F8(void *);

struct func_003B4F18_arg1 {
    char pad0[0x166];
    s8 unk166;
    char pad167[0x11];
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
};

struct func_003B4F18_v_s0 {
    char pad0[0x178];
    s32 unk178;
};
struct func_003B4F18_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x3430];
    s32 unk3448;
    s32 unk344C;
    s32 unk3450;
    s32 unk3454;
    s32 unk3458;
};

extern "C" void RaceEntryCar__setPlayerSpec(s32 *arg0, struct func_003B4F18_arg1 *arg1) {
    char *v_s0;
    v_s0 = (char *)arg0 + 0x20;
    func_004452F8(v_s0);
    ((struct func_003B4F18_v_s0 *)v_s0)->unk178 = ((struct func_003B4F18_arg0 *)arg0)->unk14 + 0x100;
    if (arg1->unk166 != 0) {
        ((struct func_003B4F18_arg0 *)arg0)->unk3448 = arg1->unk178;
        ((struct func_003B4F18_arg0 *)arg0)->unk3450 = arg1->unk17C;
        ((struct func_003B4F18_arg0 *)arg0)->unk3454 = arg1->unk180 != 0;
    }
    ((struct func_003B4F18_arg0 *)arg0)->unk344C = arg1->unk184;
    ((struct func_003B4F18_arg0 *)arg0)->unk3458 = arg1->unk188;
}
