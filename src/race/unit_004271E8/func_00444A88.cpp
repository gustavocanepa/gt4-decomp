typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;

struct Global;
extern Global D_006235A8;

struct Info {
    u16 h[11];
    u16 h16;
    u16 h18;
    u16 h1A;
    u16 h1C;
    char pad1E[0x8];
    u8 b26;
    u8 b27;
    u8 b28;
    char pad29[0x7];
};

struct Obj {
    char pad0[0x48];
    s64 id;
    char pad50[0xC0];
    u16 f110;
    u16 f112[11];
    u16 f128;
    u8 f12A;
    char pad12B;
    u16 f12C;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__IsExistID(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" u16 func_004452A8(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_00444A88(Obj *self) {
    s64 id = self->id;
    if (SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
    self->f110 = info.h16;
    self->f112[0] = info.h[0];
    self->f112[1] = info.h[1];
    self->f112[2] = info.h[2];
    self->f112[3] = info.h[3];
    self->f112[4] = info.h[4];
    self->f112[5] = info.h[5];
    self->f112[6] = info.h[6];
    self->f112[7] = info.h[7];
    self->f112[8] = info.h[8];
    self->f112[9] = info.h[9];
    self->f112[10] = info.h[10];
    self->f128 = func_004452A8(self, info.h18, info.h1C, info.h1A);
    self->f12A = func_004452A8(self, info.b26, info.b28, info.b27);
    self->f12C = self->f128;
    return 1;
}
