typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Info {
    char pad0[0x6];
    u8 unk6;
    char pad7[0x9];
};

struct Global;

struct Obj {
    char pad0[0x88];
    s64 id;
};

extern Global D_006235A8;

extern "C" void func_00443ED0(Global *g, s64 id, Info *info);

extern "C" s32 func_004465A0(Obj *self) {
    s64 id = self->id;
    if (id == -1) {
        return -1;
    }
    Info info;
    func_00443ED0(&D_006235A8, id, &info);
    return info.unk6;
}
