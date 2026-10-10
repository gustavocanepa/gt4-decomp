typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Triple {
    u8 a, b, c, pad;
};

struct Info {
    Triple t[7];
    char pad1C[0x4];
};

struct Obj {
    char pad0[0x58];
    s64 id;
    char pad60[0xF0];
    u8 f150[6];
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__IsExistID(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" u8 func_004452A8(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_00444FE0(Obj *self) {
    s64 id = self->id;
    if (SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
    self->f150[0] = func_004452A8(self, info.t[1].a, info.t[1].c, info.t[1].b);
    self->f150[1] = func_004452A8(self, info.t[4].a, info.t[4].c, info.t[4].b);
    self->f150[2] = func_004452A8(self, info.t[2].a, info.t[2].c, info.t[2].b);
    self->f150[3] = func_004452A8(self, info.t[5].a, info.t[5].c, info.t[5].b);
    self->f150[4] = func_004452A8(self, info.t[3].a, info.t[3].c, info.t[3].b);
    self->f150[5] = func_004452A8(self, info.t[6].a, info.t[6].c, info.t[6].b);
    return 1;
}
