typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x11];
    u8 f11;
    char pad12[0xE];
};

struct Obj {
    s64 id;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" s32 func_00446820(Obj *self);

extern "C" s32 func_004461F8(Obj *self) {
    s32 r = 0;
    Info info;
    if (SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->id, &info) == 0) {
        return 0;
    }
    {
        switch (info.f11) {
        case 0:
        case 3:
            if (func_00446820(self) > 0) {
                r = 1;
            }
            break;
        case 1:
            r = 3;
            break;
        case 2:
            r = 2;
            break;
        }
    }
    return r;
}
