typedef int s32;
typedef short s16;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

/* the record SPEC_DATABASE__DatabaseStorage__getRow fills for an id */
struct Info {
    char pad0[0xC];
    u16 fC;
    char padE[0x22];
};

struct Global;

struct Obj {
    char pad0[0x30];
    s64 id;
};

extern Global D_006235A8;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_004460C8(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->id, &info);
    return info.fC;
}
