typedef int s32;
typedef long long s64;

struct Info {
    s32 unk0[4];
    s32 unk10;
    char pad14[0x6C];
};

struct Global {
    char pad0[0x1E0];
    s32 unk1E0;
};

struct Obj {
    char pad0[0x38];
    s64 id;
};

extern Global D_006235A8;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" void func_00449CD8(s32 a, s32 b);

extern "C" void func_00445F30(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, self->id, &info);
    func_00449CD8(D_006235A8.unk1E0, info.unk10);
}
