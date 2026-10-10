typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Info {
    char pad0[0x38];
    u8 unk38;
    char pad39[0x7];
};

struct Global;

struct Obj {
    char pad0[0x68];
    s64 id;
};

extern Global D_006235A8;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_00446320(Obj *self) {
    s64 id = self->id;
    if (id == -1) {
        return -1;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
    return info.unk38;
}
