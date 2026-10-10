typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x6];
    u8 f6;
    char pad7[0x9];
};

struct Obj {
    char pad0[0xD0];
    s64 id;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" s32 func_00445650(Obj *self);

extern "C" s32 func_00445548(Obj *self) {
    s32 r = 0;
    s64 id = self->id;
    if (id != -1) {
        Info info;
        SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
        r = info.f6;
    }
    if (func_00445650(self)) {
        r += 4;
    }
    return r;
}
