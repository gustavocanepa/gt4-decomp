typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;

struct Global;
extern Global D_006235A8;

struct Info {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 f8;
    char pad9[0x1];
    u8 fA;
    char padB[0x1];
    u8 fC;
    u8 fD;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17;
    u8 f18;
    u8 f19;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 f1F;
    u8 f20;
    u8 f21;
    u8 f22;
    u8 f23;
    u8 f24;
    char pad25[0xB];
};

struct Obj {
    char pad0[0x128];
    u16 f128;
    u8 f12A;
    char pad12B[0x6];
    u8 f131;
    u8 f132;
    char pad133[0x6];
    u8 f139;
    u8 f13A;
    char pad13B[0x1];
    u16 f13C;
    u16 f13E;
    u8 f140;
    u8 f141;
    u8 f142;
    u8 f143;
    char pad144[0x2];
    u8 f146;
    u8 f147;
    u8 f148;
    u8 f149;
    u8 f14A;
    u8 f14B;
    u8 f14C;
    u8 f14D;
    u8 f14E;
    u8 f14F;
    u8 f150;
    u8 f151;
    u8 f152;
    u8 f153;
    u8 f154;
    u8 f155;
    u8 f156;
    u8 f157;
    char pad158[0x6];
    u16 f15E;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" s32 func_00445B78(Obj *self);

extern "C" s32 func_00444860(Obj *self, s64 id) {
    Info info;
    if (SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info) == 0) {
        return 0;
    }
    self->f128 = info.f2;
    self->f12A = info.f14;
    self->f150 = info.fE;
    self->f152 = info.fF;
    self->f154 = info.f10;
    self->f151 = info.f11;
    self->f153 = info.f12;
    self->f155 = info.f13;
    self->f131 = info.fC;
    self->f132 = info.fD;
    self->f146 = info.f19;
    self->f147 = info.f1A;
    self->f148 = info.f1B;
    self->f149 = info.f1C;
    self->f14A = info.f1D;
    self->f14B = info.f1E;
    self->f14C = info.f1F;
    self->f14D = info.f20;
    self->f139 = info.f15;
    self->f13A = info.f16;
    self->f140 = info.f17;
    self->f141 = info.f18;
    self->f14E = info.f21;
    self->f14F = info.f22;
    self->f13C = info.f4;
    self->f13E = info.f6;
    self->f142 = info.f8;
    self->f143 = info.fA;
    self->f156 = info.f24;
    self->f157 = info.f23;
    if (func_00445B78(self)) {
        self->f15E = info.f0;
    }
    return 1;
}
