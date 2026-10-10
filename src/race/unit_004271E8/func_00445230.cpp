typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x5];
    u8 f5;
    char pad6[0xA];
};

struct Obj {
    char pad0[0xF8];
    s64 id;
    char pad100[0x67];
    u8 f167;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__IsExistID(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_00445230(Obj *self) {
    s64 id = self->id;
    if (id == -1) {
        return 1;
    }
    if (SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
    self->f167 = info.f5;
    return 1;
}
