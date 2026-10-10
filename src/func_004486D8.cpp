typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x3C];
    u8 f3C;
    char pad3D[0x63];
};

extern "C" s32 func_00443F40(Global *g, s64 id);
extern "C" s32 func_00443ED0(Global *g, s64 id, Info *info);

extern "C" s32 func_004486D8(s64 id) {
    if (func_00443F40(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    func_00443ED0(&D_006235A8, id, &info);
    return info.f3C != 0;
}
