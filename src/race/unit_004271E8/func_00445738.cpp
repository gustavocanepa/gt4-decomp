typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

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

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_00445738(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->id, &info);
    u8 c = info.f23;
    if (c == 1 || c == 3) {
        return 1;
    }
    return 0;
}
