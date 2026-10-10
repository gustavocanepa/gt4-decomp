typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x23];
    u8 f23;
    char pad24[0xC];
};

struct Obj {
    char pad0[0x48];
    s64 id;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_004456C8(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->id, &info);
    switch (info.f23) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 0;
    }
    return 0;
}
