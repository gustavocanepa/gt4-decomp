typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x4];
    u8 f4;
    char pad5[0x2];
    u8 f7;
    char pad8[0x2];
    u8 fA;
    char padB[0x2];
    u8 fD;
    char padE[0x1];
    u8 fF;
    char pad10[0x2];
    u8 f12;
    char pad13[0x2];
    u8 f15;
    char pad16[0x2];
    u8 f18;
    char pad19[0x7];
};

struct Obj {
    char pad0[0xE0];
    s64 id;
    char padE8[0x6F];
    u8 f157;
    u8 f158;
    u8 f159;
    u8 f15A;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__IsExistID(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" u8 func_004452A8(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_004450D8(Obj *self) {
    s64 id = self->id;
    if (SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
    self->f157 = func_004452A8(self, 1, info.f7, info.f4);
    self->f158 = func_004452A8(self, 1, info.fD, info.fA);
    self->f159 = func_004452A8(self, 1, info.f12, info.fF);
    self->f15A = func_004452A8(self, 1, info.f18, info.f15);
    return 1;
}
