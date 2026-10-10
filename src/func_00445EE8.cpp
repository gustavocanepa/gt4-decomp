typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x1A];
    u16 f1A;
    char pad1C[0x64];
};

struct Obj {
    char pad0[0x38];
    s64 id;
};

extern char D_006244D8[];

extern "C" void func_00443ED0(Global *g, s64 id, Info *info);
extern "C" f32 func_004729A0(void *table, f32 x);

extern "C" s32 func_00445EE8(Obj *self) {
    Info info;
    func_00443ED0(&D_006235A8, self->id, &info);
    return (s32)func_004729A0(D_006244D8, info.f1A);
}
