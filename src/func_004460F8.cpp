typedef int s32;
typedef long long s64;

struct Info {
    s32 unk0[2];
    s32 unk8;
    char padC[0x74];
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

extern "C" void func_00443ED0(Global *g, s64 id, Info *info);
extern "C" void func_00449CD8(s32 a, s32 b);

extern "C" void func_004460F8(Obj *self) {
    Info info;
    func_00443ED0(&D_006235A8, self->id, &info);
    func_00449CD8(D_006235A8.unk1E0, info.unk8);
}
