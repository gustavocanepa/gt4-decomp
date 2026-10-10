typedef int s32;
typedef short s16;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

/* the record func_00443ED0 fills for an id */
struct Info {
    char pad0[0x18];
    u16 f18;
    char pad1A[0x66];
};

struct Global;

struct Obj {
    char pad0[0x38];
    s64 id;
};

extern Global D_006235A8;

extern "C" void func_00443ED0(Global *g, s64 id, Info *info);

extern "C" s32 func_00445518(Obj *self) {
    Info info;
    func_00443ED0(&D_006235A8, self->id, &info);
    return info.f18;
}
