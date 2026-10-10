typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x12];
    u8 f12;
    u8 f13;
    u8 f14;
    char pad15[0xB];
};

struct Obj {
    char pad0[0x40];
    s64 id;
    char pad48[0xE6];
    u8 f12E;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__IsExistID(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" u8 func_004452A8(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_00444B88(Obj *self) {
    s64 id = self->id;
    if (SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
    self->f12E = func_004452A8(self, info.f12, info.f14, info.f13);
    return 1;
}
