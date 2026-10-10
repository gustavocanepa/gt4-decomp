typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x6];
    u8 f6;
    char pad7[0x2];
    u8 f9;
    char padA[0x6];
};

struct Obj {
    char pad0[0xE8];
    s64 id;
    char padF0[0x66];
    u8 f156;
};

extern "C" s32 func_00443F40(Global *g, s64 id);
extern "C" s32 func_00443ED0(Global *g, s64 id, Info *info);
extern "C" u8 func_004452A8(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_004451A0(Obj *self) {
    s64 id = self->id;
    if (func_00443F40(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    func_00443ED0(&D_006235A8, id, &info);
    self->f156 = func_004452A8(self, 1, info.f9, info.f6);
    return 1;
}
