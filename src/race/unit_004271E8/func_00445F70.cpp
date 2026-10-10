typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x1C];
    u16 f1C;
    char pad1E[0x62];
};

struct Obj {
    char pad0[0x38];
    s64 id;
};

extern char PDISTD__UNIT_MANAGER[];

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" f32 func_00472A08(void *table, f32 x);

extern "C" s32 func_00445F70(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->id, &info);
    return (s32)func_00472A08(PDISTD__UNIT_MANAGER, info.f1C);
}
