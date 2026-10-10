typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0xD];
    u8 fD;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    char pad13[0xD];
};

struct Obj {
    char pad0[0x80];
    s64 id;
    char pad88[0xA9];
    u8 f131;
    u8 f132;
};

extern "C" s32 func_00443F40(Global *g, s64 id);
extern "C" s32 func_00443ED0(Global *g, s64 id, Info *info);
extern "C" u8 func_004452A8(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_00444CA0(Obj *self) {
    s64 id = self->id;
    if (func_00443F40(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    func_00443ED0(&D_006235A8, id, &info);
    self->f131 = func_004452A8(self, info.fD, info.fF, info.fE);
    self->f132 = func_004452A8(self, info.f10, info.f12, info.f11);
    return 1;
}
