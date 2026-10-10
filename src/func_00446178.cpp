typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x24];
    u8 f24;
    char pad25[0x5];
    s8 f2A;
    s8 f2B;
    u8 f2C;
    char pad2D[0x3];
};

struct Obj {
    char pad0[0x48];
    s64 id;
};

extern "C" s32 func_00443ED0(Global *g, s64 id, Info *info);

extern "C" void func_00446178(Obj *self, s32 *a, s32 *b, s32 *c, s32 *d) {
    Info info;
    func_00443ED0(&D_006235A8, self->id, &info);
    *a = info.f2C;
    *b = info.f2A;
    *c = info.f2B;
    *d = info.f24;
}
