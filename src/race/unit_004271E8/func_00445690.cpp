typedef int s32;
typedef short s16;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

/* the record SPEC_DATABASE__DatabaseStorage__getRow fills for an id */
struct Info {
    char pad0[0x23];
    u8 f23;
    char pad24[0xC];
};

struct Global;

struct Obj {
    char pad0[0x48];
    s64 id;
};

extern Global D_006235A8;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_00445690(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->id, &info);
    return (u8)(info.f23 - 1) < 2;
}
